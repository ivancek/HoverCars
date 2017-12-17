// Fill out your copyright notice in the Description page of Project Settings.

#include "StartFinish.h"


void AStartFinish::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("Start finish!"));
}

