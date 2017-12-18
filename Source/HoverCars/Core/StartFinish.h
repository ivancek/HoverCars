// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Checkpoint.h"
#include "StartFinish.generated.h"

/**
 * 
 */
UCLASS()
class HOVERCARS_API AStartFinish : public ACheckpoint
{
	GENERATED_BODY()
	
	
public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	
};
