// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeFunc.h"

// Sets default values
ATimeFunc::ATimeFunc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATimeFunc::StartTimer(UObject* WorldContextObject)
{
	if (!WorldContextObject) return;

	CachedWorldContextObject = WorldContextObject;

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	World->GetTimerManager().SetTimer(MyHandle, this, &ThisClass::TimerCallback, 1.0f, true);
	number = number + 1;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Timer on: Tick %i"), number));
		if (number > 5)
		{
			TimerCallback();
		}
	}
}

void ATimeFunc::TimerCallback()
{
	// Use CachedWorldContextObject or GetWorld() safely here
	// Your repeating timer logic...
	GetWorld()->GetTimerManager().SetTimer(MyHandle, this, &ThisClass::TimerCallback, 1.0f, true);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("TICK TICK TICK")));

}


// Called when the game starts or when spawned
void ATimeFunc::BeginPlay()
{
	Super::BeginPlay();
	StartTimer(this);
}

// Called every frame
void ATimeFunc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

