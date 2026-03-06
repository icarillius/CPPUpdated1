// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
#include "MyActorConstructor.h"

// Sets default values
AMyActorConstructor::AMyActorConstructor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &AMyActorConstructor::Trigger);
	BoxTrigger->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxTrigger;
}

void AMyActorConstructor::Trigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}


// Called when the game starts or when spawned
void AMyActorConstructor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
