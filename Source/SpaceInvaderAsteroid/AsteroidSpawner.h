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

	UPROPERTY(EditAnywhere, Category = "AsteroidClass")
		TSubclassOf<class AAsteroid> AsteroidClass;

	UPROPERTY(EditAnywhere, Category = "SpawningParameters")
		float SpawnInterval = 3;// in seconds

	UPROPERTY(EditAnywhere, Category = "SpawningParameters")
		float SpawnLimit = 15;

	UPROPERTY(EditAnywhere, Category = "SpawningParameters")
		int MapSize = 1500;// in cm

	int CurrentNumberOfAsteroids;
	float CurrentTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnAsteroid(float DeltaTime);

};
