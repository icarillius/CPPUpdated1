// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UniquePointerActor.generated.h"

struct FMyDataObj
{
public:
	int value;
	FMyDataObj(int intValue) : value(intValue) {}
};
UCLASS()
class CPPUPDATED1_API AUniquePointerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUniquePointerActor();

	TUniquePtr<FMyDataObj> UnqPtr = MakeUnique<FMyDataObj>(12);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
