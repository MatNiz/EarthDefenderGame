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
		float AsteroidSpeed = 300;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

	int MapSize = 1000;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtulana metoda po otrzymaniu obrazen od gracza
//	virtual void GetShoot() = 0;

	void Move(float DeltaTime);

};
