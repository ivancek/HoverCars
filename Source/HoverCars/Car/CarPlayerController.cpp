// Fill out your copyright notice in the Description page of Project Settings.

#include "CarPlayerController.h"
#include "Car/Car.h"


void ACarPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (auto Pawn = GetPawn())
	{
		auto Kmh = Pawn->GetVelocity().Size() / 100 * 3.6f;
		UE_LOG(LogTemp, Warning, TEXT("Speed: %f"), Kmh);
	}
}

void ACarPlayerController::SetStartFinish(AActor * StartFinish)
{
	if (auto Car = Cast<ACar>(GetPawn()))
	{
		Car->SetCurrentCheckpoint(StartFinish);
	}
}