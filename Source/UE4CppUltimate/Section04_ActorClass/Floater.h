// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

class UDemoObject;
UCLASS()
class UE4CPPULTIMATE_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere, Category="StaticMesh")
	UStaticMeshComponent* MyStaticMesh;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FloaterVariable")
	FVector InitialLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="FloaterVariable")
	FVector PlaceLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FloaterVariable")
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariable")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FloaterVariable")
	bool bInitializeFloaterLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FloaterVariable")
	FVector WorldOrigin;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
