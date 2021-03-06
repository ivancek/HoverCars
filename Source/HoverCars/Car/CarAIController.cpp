// Fill out your copyright notice in the Description page of Project Settings.

#include "CarAIController.h"
#include "CarMovementComponent.h"
#include "Car/Car.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"

void ACarAIController::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent = GetPawn()->FindComponentByClass<UCarMovementComponent>();
	
	if (ensure(MovementComponent))
	{
		MovementComponent->SetSidewaysStabilizeAmount(0.08f);
	}

	GetWorldTimerManager().SetTimer(FlipTimer, this, &ACarAIController::FlipIfNeeded, 2, true, 2);
}


void ACarAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Target || !GetPawn())
	{
		GetWorldTimerManager().ClearTimer(FlipTimer);
		return; 
	}

	MoveToTarget(Target);
}

void ACarAIController::SetNextCheckpoint(AActor * Checkpoint)
{
	SetTarget(Checkpoint);
}

void ACarAIController::SetStartFinish(AActor * StartFinish)
{
	if (auto Car = Cast<ACar>(GetPawn()))
	{
		Car->SetCurrentCheckpoint(StartFinish);
		SetTarget(StartFinish);
	}
}

void ACarAIController::SetTarget(AActor* TargetToSet)
{
	Target = TargetToSet;
}

void ACarAIController::MoveToTarget(AActor* Target)
{
	MoveToActor(Target, AcceptanceRadius, false, true, true, 0, true);
}

void ACarAIController::FlipIfNeeded()
{
	if (!MovementComponent->IsUpright())
	{
		MovementComponent->IntendFlipRight();
	}
}

