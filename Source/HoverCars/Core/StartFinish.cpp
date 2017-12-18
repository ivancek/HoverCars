// Fill out your copyright notice in the Description page of Project Settings.

#include "StartFinish.h"
#include "Car/Car.h"
#include "Car/CarAIController.h"
#include "Engine/World.h"
#include "Core/StandardRaceGameMode.h"

void AStartFinish::NotifyActorBeginOverlap(AActor * OtherActor)
{
	AActor::NotifyActorBeginOverlap(OtherActor);

	if (auto Car = Cast<ACar>(OtherActor))
	{
		/// First check if we're going wrong way
		auto DotProduct = FVector::DotProduct(Car->GetVelocity(), GetActorForwardVector().GetSafeNormal());
		if (DotProduct < 0)
		{
			WrongWay();
		}

		/// Check for validity. Ignore the first pass.
		auto DesiredCheckpoint = Cast<ACheckpoint>(Car->GetCurrentCheckpoint())->NextCheckpoint;
		if (Car->GetCurrentLap() >= 0 && DesiredCheckpoint != this)
		{
			return;
		}

		/// This checkpoint becomes car's current checkpoint.
		Car->SetCurrentCheckpoint(this);
		Car->IncrementLap();

		/// Need to set AIController's next checkpoint so it can feed the nav mesh.
		bool IsPlayer = true;
		auto Controller = Car->GetController();
		if (auto AIController = Cast<ACarAIController>(Controller))
		{
			AIController->SetNextCheckpoint(NextCheckpoint);
			IsPlayer = false;
		}

		/// Call blueprint implementable
		CheckpointPassed(IsPlayer);

		/// Check if the race is complete for this car
		if (auto GameMode = Cast<AStandardRaceGameMode>(GetWorld()->GetAuthGameMode()))
		{
			if (GameMode->IsRaceComplete(Car->GetCurrentLap()))
			{
				/// Unpossess the Pawn. This will disable Input for PlayerController
				Controller->UnPossess();
		
				/// This will make the AI car stop racing.
				if (auto AIController = Cast<ACarAIController>(Controller))
				{
					AIController->StopMovement();
					AIController->SetNextCheckpoint(nullptr);
				}
			}
		}
	}
}