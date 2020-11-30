// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	PlaceLocation = FVector(0.0f);
	InitialLocation = FVector(0.0f);
	bInitializeFloaterLocation = false;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	PlaceLocation = this->GetActorLocation();
	if(bInitializeFloaterLocation) 
	{
		this->SetActorLocation(PlaceLocation);
	}
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bShouldFloat) 
	{
		this->AddActorLocalOffset(FVector(1.0f,1.0f,1.0f),)
	}
}
