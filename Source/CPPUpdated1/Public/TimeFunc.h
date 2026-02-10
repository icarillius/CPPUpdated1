// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeFunc.generated.h"

UCLASS()
class CPPUPDATED1_API ATimeFunc : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeFunc();

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	void StartTimer(UObject* WorldContextObject);

	void TimerCallback();

	FTimerHandle MyHandle;
	int number = 1;

private:
	// Store world context object pointer if needed
	UObject* CachedWorldContextObject;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
