// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class SPACEINVADERASTEROID_API AAsteroid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsteroid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "AsteroidClass")
		TSubclassOf<class AAsteroid> AsteroidClass;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		float AsteroidSpeed = 100;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		float AsteroidLifeTime = 6;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		int MapSize = 1500;
	
	float CurrentTime;
	int AsteroidSize;
	static int NumberOfAsteroids;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Decay();

	void Move(float DeltaTime);

	void SetMeshSize();

	int GetAsteroidSize();
	void SetAsteroidSize(int Size);

	static int GetNumberOfAsteroids();
};

int AAsteroid::NumberOfAsteroids = 0;