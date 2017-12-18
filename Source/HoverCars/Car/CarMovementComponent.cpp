// Fill out your copyright notice in the Description page of Project Settings.

#include "CarMovementComponent.h"
#include "CarThruster.h"
#include "Engine/World.h"

void UCarMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	CarRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UCarMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsGrounded()) { return; }

	Hover();
	Stabilize(DeltaTime);
}

void UCarMovementComponent::Initialise(UCarThruster* FrontLeftThrusterToSet, UCarThruster* FrontRightThrusterToSet, UCarThruster* RearLeftThrusterToSet, UCarThruster* RearRightThrusterToSet)
{
	if (!ensure(FrontLeftThrusterToSet && FrontRightThrusterToSet && RearLeftThrusterToSet && RearRightThrusterToSet))
	{ 
		UE_LOG(LogTemp, Warning, TEXT("Thrusters missing!"));
	}
 
	FrontLeftThruster = FrontLeftThrusterToSet;
	FrontRightThruster = FrontRightThrusterToSet;

	RearLeftThruster = RearLeftThrusterToSet;
	RearRightThruster = RearRightThrusterToSet;
}

// Is upright as long as UpVector().Z is larger than 1.
bool UCarMovementComponent::IsUpright()
{
	if (!CarRoot) { return true; }

	return CarRoot->GetUpVector().GetSafeNormal().Z > 0.5f;
}

// The car is grounded when his line trace hits the floor.
bool UCarMovementComponent::IsGrounded()
{
	FHitResult HitResult;
	auto CompLocation = CarRoot->GetComponentLocation();
	auto UpNormal = CarRoot->GetUpVector().GetSafeNormal();
	auto EndLocation = CompLocation - (UpNormal * GroundedDistance);

	return GetWorld()->LineTraceSingleByChannel(OUT HitResult, CompLocation, EndLocation, ECollisionChannel::ECC_Visibility);
}

void UCarMovementComponent::IntendMoveForward(float Throw)
{
	if (!FrontLeftThruster || !FrontRightThruster || !RearLeftThruster || !RearRightThruster) { return; }

	// No throttle when not grounded.
	if (!IsGrounded()) { return; }

	Throw = FMath::Clamp(Throw, -1.0f, 1.0f);

	FrontLeftThruster->SetThrottle(Throw * ThrustPower);
	FrontRightThruster->SetThrottle(Throw * ThrustPower);

	RearLeftThruster->SetThrottle(Throw * ThrustPower);
	RearRightThruster->SetThrottle(Throw * ThrustPower);
}

void UCarMovementComponent::IntendTurn(float Throw)
{
	Throw = FMath::Clamp(Throw, -1.0f, 1.0f);

	if (IsGrounded())
	{
		CarRoot->SetAngularDamping(MaxAngularDamp); // Need good damping for steering
	}
	else
	{
		Throw *= AirTurnAmount;
		CarRoot->SetAngularDamping(0); // No damping when in air. Allows for spins.
	}

	auto PreviousSign = FMath::Sign(PreviousThrow);
	auto CurrentSign = FMath::Sign(Throw);

	/// Break Yaw angular velocity when trying to steer the other way.
	if (Throw != 0 && PreviousSign != CurrentSign)
	{
		PreviousThrow = Throw;
		
		auto AngularVeolocity = CarRoot->GetPhysicsAngularVelocityInDegrees();
		CarRoot->SetPhysicsAngularVelocityInDegrees(FVector(AngularVeolocity.X, AngularVeolocity.Y, AngularVeolocity.Z * YawKeepPercent));
	}

	CarRoot->AddTorqueInRadians(FVector(0, 0, Throw) * TurnForce);
}

void UCarMovementComponent::IntendFlipLeft()
{
	if (IsGrounded()) { return; } // Don't flip when grounded

	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	if (IsUpright())
	{
		FrontLeftThruster->FlipBurst(FlipForce * AirFlipForcePercent);
		RearLeftThruster->FlipBurst(FlipForce * AirFlipForcePercent);
	}
	else
	{
		FrontLeftThruster->FlipBurst(FlipForce);
		RearLeftThruster->FlipBurst(FlipForce);
	}
}


void UCarMovementComponent::IntendFlipRight()
{
	if (IsGrounded()) { return; } // Don't flip when grounded

	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	if (IsUpright())
	{
		FrontRightThruster->FlipBurst(FlipForce * AirFlipForcePercent);
		RearRightThruster->FlipBurst(FlipForce * AirFlipForcePercent);
	}
	else
	{
		FrontRightThruster->FlipBurst(FlipForce); 
		RearRightThruster->FlipBurst(FlipForce);
	}
}

// Applies hover force to keep the vehicle above ground.
void UCarMovementComponent::Hover()
{
	if (!FrontLeftThruster || !FrontRightThruster || !RearRightThruster || !RearLeftThruster) { return; }

	FrontRightThruster->Hover(HoverDistance);
	FrontLeftThruster->Hover(HoverDistance);
	
	RearRightThruster->Hover(HoverDistance);
	RearLeftThruster->Hover(HoverDistance);
}

// Applies sideways force to keep the vehicle from sliding.
void UCarMovementComponent::Stabilize(float DeltaTime)
{
	if (!IsGrounded()) { return; }

	auto SlippageSpeed = FVector::DotProduct(CarRoot->GetRightVector(), CarRoot->GetComponentVelocity());
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * CarRoot->GetRightVector();
	auto CorrectionForce = CarRoot->GetMass() * CorrectionAcceleration;

	CarRoot->AddForce(CorrectionForce * SidewaysStabilizeAmount);

	/// Damp angular velocity on Y and X.
	auto AngularVelocity = CarRoot->GetPhysicsAngularVelocityInDegrees();
	if (FMath::Abs(AngularVelocity.X) > 10 || FMath::Abs(AngularVelocity.Y) > 10)
	{
		CarRoot->SetAngularDamping(3);
	}
}

void UCarMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto ForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto TurnThrow = FVector::CrossProduct(ForwardDirection, ForwardIntention);
	
	auto Sign = FMath::Sign(TurnThrow.Z); // Get the sign of current throw.

	IntendTurn(Sign);

	// When going backwards, reverse turn throw so the car behaves as if on wheels.
	auto ForwardSpeed = FVector::DotProduct(CarRoot->GetForwardVector(), CarRoot->GetComponentVelocity().GetSafeNormal());
	auto Speed = CarRoot->GetComponentVelocity().Size();
	auto ForwardThrow = FVector::DotProduct(ForwardDirection, ForwardIntention);
	
	// Attempt to brake.
	if (FMath::Abs(TurnThrow.Z) > 0.3f && Speed > 8000)
	{
		IntendMoveForward(-1);
	}
	else
	{
		IntendMoveForward(ForwardThrow);
	}
}
