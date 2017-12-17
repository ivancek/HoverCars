// Fill out your copyright notice in the Description page of Project Settings.

#include "Checkpoint.h"
#include "Car/Car.h"
#include "Car/CarAIController.h"
#include "Car/CarPlayerController.h"
#include "Components/BoxComponent.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(FName("Root"));

	Trigger = CreateDefaultSubobject<UBoxComponent>(FName("Trigger"));
	Trigger->SetBoxExtent(FVector(1000, 2500.0f, 500.0f));
	Trigger->SetCollisionProfileName(TEXT("Checkpoint"));
	Trigger->SetRelativeTransform(FTransform(FVector(0, 0, 500)));
	Trigger->SetCanEverAffectNavigation(false);
	
	Trigger->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	
	if (!ensure(NextCheckpoint))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s missing next checkpoint!"), *GetName());
	}
}

// Called every frame
void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckpoint::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (auto Car = Cast<ACar>(OtherActor))
	{
		auto Controller = Car->GetController();

		if (auto AIController = Cast<ACarAIController>(Controller))
		{
			if (NextCheckpoint)
			{
				AIController->SetTarget(NextCheckpoint);
			}
		}
		else if (auto PlayerController = Cast<ACarPlayerController>(Controller))
		{
			PlayerController->CheckpointPassed();
		}
	}
}
