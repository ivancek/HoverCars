// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HoverCarsGameModeBase.h"
#include "StandardRaceGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HOVERCARS_API AStandardRaceGameMode : public AHoverCarsGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	bool IsRaceComplete(int CurrentLap);
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
	int NumberOfLaps = 10;
	
};
