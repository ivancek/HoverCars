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

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendFlipLeft();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendFlipRight();

	UFUNCTION(BlueprintCallable, Category = "Input")
	bool IsUpright();
	
	void SetSidewaysStabilizeAmount(float Amount);

	//virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	virtual void RequestPathMove(const FVector& MoveInput) override;

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
	float SidewaysStabilizeAmount = 0.04f;

	// Amount of turn ability in air force (0...1)
	UPROPERTY(EditDefaultsOnly, Category = "Setup", meta = (ClampMin = "0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AirTurnAmount = 0.25f;

	// Amount of YAW momentum we keep when attempting to steer the opposite way. This is to allow for faster counter steer.
	UPROPERTY(EditDefaultsOnly, Category = "Setup", meta = (ClampMin = "0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float YawKeepPercent = 0.5f;

	// Amount of flip force we apply when airborn and upright 
	UPROPERTY(EditDefaultsOnly, Category = "Setup", meta = (ClampMin = "0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AirFlipForcePercent = 0.1f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float GroundedDistance = 200;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float TurnForce = 120000000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float FlipForce = 50000000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float HoverDistance = 200;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ThrustPower = 1000000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxAngularDamp = 3;

	float PreviousThrow = 0;
};
