// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Car.generated.h"

UCLASS()
class HOVERCARS_API ACar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AActor* GetCurrentCheckpoint();
	void SetCurrentCheckpoint(AActor* Checkpoint);

	void IncrementLap();
	int GetCurrentLap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	int LapsPassed = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	int CheckpointsPassed = 0;
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	AActor* CurrentCheckpoint = nullptr;
};
