// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// adds the box component for the collision box
#include "Components/BoxComponent.h"
//include shared pointers
#include "Templates/SharedPointer.h"
#include "SharedPointerActor.generated.h"

//Sets an initial struct to hold data.
struct FMyData
{
public:
	int value;
	FMyData(int intValue) : value(intValue) {}
	//added public decrement function
	int DecrementValue() 
	{
		return value--;
	}
}; 
UCLASS()
class CPPUPDATED1_API ASharedPointerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASharedPointerActor();
	//Creates a shared poitner and calls the data of the shared data container.
	TSharedPtr<FMyData> Pointer1 = MakeShared<FMyData>(4);

	//adds the box trigger for the collider.
	UPROPERTY()
	UBoxComponent* BoxTrigger;
	UFUNCTION()
	void Trigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
