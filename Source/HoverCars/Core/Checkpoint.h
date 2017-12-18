// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"

class UBoxComponent;
class ACar;

UCLASS()
class HOVERCARS_API ACheckpoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* Trigger = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void WrongWay();

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void CheckpointPassed(bool IsPlayer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ACheckpoint* NextCheckpoint = nullptr;

private:
	
};
