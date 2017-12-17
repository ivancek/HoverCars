// Fill out your copyright notice in the Description page of Project Settings.

#include "CarAIController.h"
#include "CarMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"

void ACarAIController::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent = GetPawn()->FindComponentByClass<UCarMovementComponent>();
	
	if (!ensure(MovementComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find movement component"));
	}

	GetWorldTimerManager().SetTimer(FlipTimer, this, &ACarAIController::FlipIfNeeded, 2, true, 2);
}


void ACarAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Target || !GetPawn())
	{
		StopMovement();
		GetWorldTimerManager().ClearTimer(FlipTimer);
		return; 
	}

	MoveToTarget(Target);
}

void ACarAIController::SetTarget(AActor* TargetToSet)
{
	Target = TargetToSet;
}

void ACarAIController::MoveToTarget(AActor* Target)
{
	MoveToActor(Target, AcceptanceRadius);
}

void ACarAIController::FlipIfNeeded()
{
	if (!MovementComponent->IsUpright())
	{
		MovementComponent->IntendFlipRight();
	}
}

