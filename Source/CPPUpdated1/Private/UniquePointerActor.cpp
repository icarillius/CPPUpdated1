// Fill out your copyright notice in the Description page of Project Settings.


#include "UniquePointerActor.h"

// Sets default values
AUniquePointerActor::AUniquePointerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	}

// Called when the game starts or when spawned
void AUniquePointerActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (UnqPtr.IsValid())
	{
		int holder = UnqPtr->value;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Builds")));

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Unique Pointer Value %d"), holder));

	}
}

// Called every frame
void AUniquePointerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

