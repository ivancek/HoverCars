// Fill out your copyright notice in the Description page of Project Settings.

#include "CarAIController.h"
#include "CarMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

void ACarAIController::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent = GetPawn()->FindComponentByClass<UCarMovementComponent>();

	if (!ensure(MovementComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find movement component"));
	}
}


void ACarAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToTarget();
}

void ACarAIController::MoveToTarget()
{
	auto Target = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!Target) { return; }

	MoveToActor(Target, AcceptanceRadius);
}

