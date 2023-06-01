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


	UPROPERTY(EditAnywhere, Category = "Speed")
		float AsteroidSpeed = 200;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "AsteroidClass")
		TSubclassOf<class AAsteroid> AsteroidClass;

	int MapSize = 1000;

	float AsteroidLifeTime = 5;
	float CurrentTime = 0;

	int AsteroidSize;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Decay();

	void Move(float DeltaTime);

	void SetMeshSize();

	int GetAsteroidSize()
	{
		return this->AsteroidSize;
	}
	void SetAsteroidSize(int Size)
	{
		this->AsteroidSize = Size;
	}


};



/*

*/