// Fill out your copyright notice in the Description page of Project Settings.

#include "CarAIController.h"
#include "CarMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void ACarAIController::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent = GetPawn()->FindComponentByClass<UCarMovementComponent>();
	
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Checkpoint"), OUT Targets);

	if (!ensure(MovementComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find movement component"));
	}
}


void ACarAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Targets.Num() < 0) { return; }
	
	MoveToTarget(Targets[0]);
}

void ACarAIController::SetTargets(TArray<AActor*> TargetsToSet)
{
	Targets = TargetsToSet;
}

void ACarAIController::MoveToTarget(AActor* Target)
{
	MoveToActor(Target, AcceptanceRadius);
}

