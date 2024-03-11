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


public:
	// Called every frame
	virtual	void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float AsteroidSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		int MapSize;

	void Move(float DeltaTime);


	void SetMeshSize();
	int GetAsteroidSize();
	void SetAsteroidSize(int Size);

private:
	UPROPERTY(EditDefaultsOnly, Category = "References")
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditDefaultsOnly, Category = "References")
		TSubclassOf<class AAsteroid> AsteroidClass;

	int AsteroidSize;


	UFUNCTION(BlueprintCallable)
		void Decay();
};