// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerFuncLambda.h"
#include "TimerManager.h"

// Sets default values
ATimerFuncLambda::ATimerFuncLambda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATimerFuncLambda::BeginPlay()
{
	Super::BeginPlay();

	TWeakObjectPtr<ATimerFuncLambda> WeakThis(this);

	FTimerDelegate TimerDel = FTimerDelegate::CreateLambda([WeakThis, &MyHandle = MyHandle]()
		{
			if (!WeakThis.IsValid())
				return;

			WeakThis->GetWorldTimerManager().ClearTimer(MyHandle);

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("CLEAR TIMER")));
		});
	GetWorldTimerManager().SetTimer(MyHandle, TimerDel, 1.0f, true);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("RUN TIMER")));

}

// Called every frame
void ATimerFuncLambda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

