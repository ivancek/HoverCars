// Fill out your copyright notice in the Description page of Project Settings.

#include "CarPlayerController.h"
#include "GameFramework/Pawn.h"

void ACarPlayerController::CheckpointPassed()
{
	UE_LOG(LogTemp, Warning, TEXT("Player controller, checkpoint passed."));
}