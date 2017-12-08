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

bool UCarMovementComponent::IsGrounded()
{
	FHitResult HitResult;
	auto CompLocation = CarRoot->GetComponentLocation();
	auto UpNormal = CarRoot->GetUpVector().GetSafeNormal();
	auto EndLocation = CompLocation - (UpNormal * GroundedDistance);

	if (GetWorld()->LineTraceSingleByChannel(OUT HitResult, CompLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		UE_LOG(LogTemp, Warning, TEXT("Grounded!"));
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("not Grounded!"));
	return false;
}

void UCarMovementComponent::IntendMoveForward(float Throw)
{
	if (!FrontLeftThruster || !FrontRightThruster || !RearLeftThruster || !RearRightThruster) { return; }

	// No throttle when not grounded.
	if (!IsGrounded()) { return; }

	FrontLeftThruster->SetThrottle(Throw);
	FrontRightThruster->SetThrottle(Throw);

	RearLeftThruster->SetThrottle(Throw);
	RearRightThruster->SetThrottle(Throw);
}

void UCarMovementComponent::IntendTurn(float Throw)
{
	auto ForwardSpeed = FVector::DotProduct(CarRoot->GetForwardVector(), CarRoot->GetComponentVelocity());

	// Steer 4 times less when not grounded.
	if (!IsGrounded()) { return; }

	// When going backwards, reverse turn throw so the car behaves as if on wheels.
	if (ForwardSpeed < 0)
	{
		Throw = -Throw;
	}

	CarRoot->AddTorque(FVector(0, 0, Throw) * TurnForce);
}

// Applies hover force to keep the vehicle above ground.
void UCarMovementComponent::Hover()
{
	if (!FrontLeftThruster || !FrontRightThruster || !RearRightThruster || !RearLeftThruster) { return; }

	FrontRightThruster->Hover();
	FrontLeftThruster->Hover();
	
	RearRightThruster->Hover();
	RearLeftThruster->Hover();
}

// Applies sideways force to keep the vehicle from sliding.
void UCarMovementComponent::Stabilize(float DeltaTime)
{
	if (!IsGrounded()) { return; }

	auto SlippageSpeed = FVector::DotProduct(CarRoot->GetRightVector(), CarRoot->GetComponentVelocity());
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * CarRoot->GetRightVector();
	auto CorrectionForce = CarRoot->GetMass() * CorrectionAcceleration;

	CarRoot->AddForce(CorrectionForce * SidewaysStabilizeAmount);
}

void UCarMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	if (!IsGrounded()) { return; }

	auto ForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(ForwardDirection, ForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto TurnThrow = FVector::CrossProduct(ForwardDirection, ForwardIntention);
	IntendTurn(TurnThrow.Z);

}
