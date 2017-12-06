// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CarAIController.generated.h"


class UCarMovementComponent;
/**
 * Responsible for handling AI fly-by-wire
 */
UCLASS()
class HOVERCARS_API ACarAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetTargets(TArray<AActor*> TargetsToSet);
	
	void MoveToTarget(AActor* Target);

	TArray<AActor*> Targets;
	UCarMovementComponent* MovementComponent = nullptr;

	float AcceptanceRadius = 300;
	
};
