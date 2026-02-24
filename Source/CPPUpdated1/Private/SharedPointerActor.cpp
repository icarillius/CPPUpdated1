// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
#include "SharedPointerActor.h"

// Sets default values
ASharedPointerActor::ASharedPointerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates the collision Box
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ASharedPointerActor::Trigger);
	BoxTrigger->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxTrigger;
	}

void ASharedPointerActor::Trigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//checks if any data is in pointer 1 then undertake this.
	if (Pointer1.IsValid())
	{
		int currentvalue = Pointer1->DecrementValue();
		// if no decrement Pointer1->value
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Point 1 Value %d"), currentvalue));
		//resets the value of the pointer and empties it.
		TSharedPtr<FMyData>Pointer2 = Pointer1;

		if (Pointer2.IsValid())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Point 2 Value %d"), Pointer2->value));
			TSharedRef<FMyData> Ref = MakeShared<FMyData>(100);
			TSharedPtr<FMyData> PtrFromRef = Ref;
			check(PtrFromRef.IsValid());
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Reference Value %d"), PtrFromRef->value));

		}

	}	
}


// Called when the game starts or when spawned
void ASharedPointerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASharedPointerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

