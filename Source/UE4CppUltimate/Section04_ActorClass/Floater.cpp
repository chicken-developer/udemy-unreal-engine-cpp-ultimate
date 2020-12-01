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
	WorldOrigin = FVector(0.0f);
	bShouldFloat = false;
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
	FHitResult HitResult;
	FHitResult* HitResultPointer = nullptr;
	FVector LocalOffset = FVector(200.0f, 0.0f, 0.0f);
	//this->AddActorLocalOffset(LocalOffset, true, &HitResult); 
	//this->AddActorWorldOffset(LocalOffset, true, HitResultPointer); // For world offset

	FRotator Rotation = FRotator(0.0f,30.0f,0.0f);
	//inPitch for Y Rotation
	//inYaw for Z Rotation
	//inRoll for X Rotation
	this->AddActorLocalRotation(Rotation);
	
	//this->AddActorLocalRotation(Rotation); // For world offset

}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bShouldFloat) 
	{
		FHitResult HitResult;
		FVector HitLocation = HitResult.Location;
		this->AddActorLocalOffset(InitialDirection, true, &HitResult);
	}
}
