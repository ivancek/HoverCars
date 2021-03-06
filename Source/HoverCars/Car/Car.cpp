// Fill out your copyright notice in the Description page of Project Settings.

#include "Car.h"


// Sets default values
ACar::ACar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* ACar::GetCurrentCheckpoint()
{
	return CurrentCheckpoint;
}

void ACar::SetCurrentCheckpoint(AActor* Checkpoint)
{
	CurrentCheckpoint = Checkpoint;
}

void ACar::IncrementLap()
{
	LapsPassed++;
}

int ACar::GetCurrentLap()
{
	return LapsPassed;
}
