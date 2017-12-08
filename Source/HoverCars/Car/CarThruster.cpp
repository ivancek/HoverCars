// Fill out your copyright notice in the Description page of Project Settings.

#include "CarThruster.h"
#include "Engine/World.h"

void UCarThruster::BeginPlay()
{
	Super::BeginPlay();

	CarRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UCarThruster::SetThrottle(float Throw)
{
	Throw = FMath::Clamp(Throw, -1.0f, 1.0f);

	auto ForceApplied = GetForwardVector() * Throw * ThrustPower;
	auto ForceLocation = GetComponentLocation();
	
	CarRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UCarThruster::Hover()
{
	FHitResult HitResult;
	auto CompLocation = GetComponentLocation();
	auto UpNormal = GetUpVector().GetSafeNormal();
	auto EndLocation = CompLocation - (UpNormal * HoverDistance);

	if (GetWorld()->LineTraceSingleByChannel(OUT HitResult, CompLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		/// Hover force
		auto ImpactNormal = HitResult.ImpactNormal;
		auto Distance = (HitResult.Location - CompLocation).Size();
		auto DistancePercent = Distance / HoverDistance;
		auto VerticalForce = CarRoot->GetMass() * GetWorld()->GetGravityZ();
		auto ForceToApply = FMath::Lerp<float>(-VerticalForce, 0, DistancePercent);
		auto FinalForce = ForceToApply * ImpactNormal;
		
		/// Bounce correction force
		auto SlippageSpeed = FVector::DotProduct(CarRoot->GetUpVector(), CarRoot->GetComponentVelocity());
		auto CorrectionAcceleration = -SlippageSpeed * CarRoot->GetUpVector();
		auto CorrectionForce = CarRoot->GetMass() * CorrectionAcceleration / 2;

		CarRoot->AddForceAtLocation(FinalForce + CorrectionForce, CompLocation);

		//CarRoot->SetAngularDamping(3);
	
		/*UE_LOG(LogTemp, Warning, TEXT("Final Force: %s"), *FinalForce.ToString())*/
	}
}
