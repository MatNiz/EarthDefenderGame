// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyProjectile.generated.h"

UCLASS()
class SPACEINVADERASTEROID_API AEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float ProjectileSpeed = 500;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float ProjectileLifeTime = 10; //in seconds

	float CurrentTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);

};
