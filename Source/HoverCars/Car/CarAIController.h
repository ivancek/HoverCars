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
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetNextCheckpoint(AActor* Checkpoint);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetStartFinish(AActor* StartFinish);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	UCarMovementComponent* MovementComponent = nullptr;
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetTarget(AActor* TargetToSet);

private:
	
	void MoveToTarget(AActor* Target);

	void FlipIfNeeded();

	AActor* Target;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 300;
	
	FTimerHandle FlipTimer;
};
