// Fill out your copyright notice in the Description page of Project Settings.

#include "StartFinish.h"
#include "Car/Car.h"

void AStartFinish::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (auto Car = Cast<ACar>(OtherActor))
	{
		Car->IncrementLap();
	}
}

