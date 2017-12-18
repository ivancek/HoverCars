// Fill out your copyright notice in the Description page of Project Settings.

#include "CarPlayerController.h"
#include "Car/Car.h"

void ACarPlayerController::SetStartFinish(AActor * StartFinish)
{
	if (auto Car = Cast<ACar>(GetPawn()))
	{
		Car->SetCurrentCheckpoint(StartFinish);
	}
}