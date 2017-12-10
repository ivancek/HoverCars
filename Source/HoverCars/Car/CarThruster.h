// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CarThruster.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOVERCARS_API UCarThruster : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	void SetThrottle(float Throw);
	void Hover(float HoverDistance);
	void FlipBurst(float Force);
	
private:
	UPrimitiveComponent* CarRoot = nullptr;
};
