// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "CarMovementComponent.generated.h"

class UCarThruster;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOVERCARS_API UCarMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UCarThruster* FrontLeftThrusterToSet, UCarThruster* FrontRightThrusterToSet, UCarThruster* RearLeftThrusterToSet, UCarThruster* RearRightThrusterToSet);

	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurn(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	void Hover();
	void Stabilize(float DeltaTime);
	
	bool IsGrounded();
	
	UCarThruster* FrontLeftThruster = nullptr;
	UCarThruster* FrontRightThruster = nullptr;
	UCarThruster* RearLeftThruster = nullptr;
	UCarThruster* RearRightThruster = nullptr;

	UPrimitiveComponent* CarRoot = nullptr;

	// Amount of stabilizing force (0...1)
	UPROPERTY(EditDefaultsOnly, Category = "Setup", meta = (ClampMin = "0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float SidewaysStabilizeAmount = 0.025f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float GroundedDistance = 200;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float TurnForce = 50000;
};
