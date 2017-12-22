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

	auto BoxExtent = FVector(1000, 2500, 500);

	Trigger = CreateDefaultSubobject<UBoxComponent>(FName("Trigger"));
	Trigger->SetBoxExtent(BoxExtent);
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

	if (!NextCheckpoint) { return; }

	if (auto Car = Cast<ACar>(OtherActor))	
	{
		/// First check if we're going wrong way
		auto DotProduct = FVector::DotProduct(Car->GetVelocity(), GetActorForwardVector().GetSafeNormal());

		if (DotProduct < 0)
		{
			WrongWay();
		}

		auto DesiredCheckpoint = Cast<ACheckpoint>(Car->GetCurrentCheckpoint())->NextCheckpoint;
		if (DesiredCheckpoint != this)
		{
			return;
		}

		/// This checkpoint becomes car's current checkpoint.
		Car->SetCurrentCheckpoint(this);

		/// Need to set AIController's next checkpoint so it can feed the nav mesh.
		auto Controller = Car->GetController();
		bool IsPlayer = true;
		if (auto AIController = Cast<ACarAIController>(Controller))
		{
			AIController->SetNextCheckpoint(NextCheckpoint);
			IsPlayer = false;
		}

		/// Call blueprint implementable
		CheckpointPassed(IsPlayer);
	}
}
