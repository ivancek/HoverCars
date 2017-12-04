// Fill out your copyright notice in the Description page of Project Settings.

#include "CarMovementComponent.h"
#include "CarThruster.h"

void UCarMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	CarRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UCarMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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

void UCarMovementComponent::IntendMoveForward(float Throw)
{
	if (!FrontLeftThruster || !FrontRightThruster || !RearLeftThruster || !RearRightThruster) { return; }

	FrontLeftThruster->SetThrottle(Throw);
	FrontRightThruster->SetThrottle(Throw);

	RearLeftThruster->SetThrottle(Throw);
	RearRightThruster->SetThrottle(Throw);
}

void UCarMovementComponent::IntendTurn(float Throw)
{
	
	auto ForwardSpeed = FVector::DotProduct(CarRoot->GetForwardVector(), CarRoot->GetComponentVelocity());

	/*UE_LOG(LogTemp, Warning, TEXT("ForwardSpeed: %f"), ForwardSpeed);*/

	// When going backwards, reverse turn throw so the car behaves as if on wheels.
	if (ForwardSpeed < 0)
	{
		Throw = -Throw;
	}

	if (Throw > 0)
	{
		IntendTurnRight(Throw);
	}
	else
	{
		IntendTurnLeft(-Throw);
	}
}

// Expects a positive input to properly turn.
void UCarMovementComponent::IntendTurnRight(float Throw)
{
	if (!FrontRightThruster || !RearLeftThruster) { return; }

	RearLeftThruster->SetThrottle(Throw);
}

// Expects a positive input to properly turn.
void UCarMovementComponent::IntendTurnLeft(float Throw)
{
	if (!FrontLeftThruster || !RearRightThruster) { return; }

	RearRightThruster->SetThrottle(Throw);
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
	auto SlippageSpeed = FVector::DotProduct(CarRoot->GetRightVector(), CarRoot->GetComponentVelocity());
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * CarRoot->GetRightVector();
	auto CorrectionForce = CarRoot->GetMass() * CorrectionAcceleration;

	CarRoot->AddForce(CorrectionForce * SidewaysStabilizeAmount);
}

void UCarMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto ForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(ForwardDirection, ForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto TurnThrow = FVector::CrossProduct(ForwardDirection, ForwardIntention);
	IntendTurn(TurnThrow.Z);
}
