// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
#include "MyActorConstructor.h"

// Sets default values
AMyActorConstructor::AMyActorConstructor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	//Needed for events
	BoxTrigger->SetGenerateOverlapEvents(true);
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &AMyActorConstructor::OnOverlapBegin);
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &AMyActorConstructor::OnOverlapEnd);
	//Make box appear
	BoxTrigger->SetHiddenInGame(false);
	//Set box size
	BoxTrigger->InitBoxExtent(FVector(150.f, 150.f, 100.f));
	//Set box root
	RootComponent = BoxTrigger;
}

void AMyActorConstructor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Overlap Box")));
	}
}

void AMyActorConstructor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Exit Box")));
	}
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
