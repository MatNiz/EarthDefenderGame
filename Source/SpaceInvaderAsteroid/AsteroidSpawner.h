// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidSpawner.generated.h"

UCLASS()
class SPACEINVADERASTEROID_API AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "SpawningParameters")
		float SpawnInterval = 7;// in seconds

	UPROPERTY(EditAnywhere, Category = "SpawningParameters")
		float SpawnLimit = 10;

	int MapSize = 1000;

	float CurrentTime;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AAsteroid> AsteroidClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnAsteroid(float DeltaTime);

};
