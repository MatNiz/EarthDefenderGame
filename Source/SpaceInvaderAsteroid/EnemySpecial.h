// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpecial.generated.h"

UCLASS()
class SPACEINVADERASTEROID_API AEnemySpecial : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemySpecial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AEnemyProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float CurrentAngle = 0; //in degrees

	UPROPERTY(EditAnywhere, Category = "Movement")
		float EnemySpecialMovementSpeed = 0.05;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float EnemySpeedOfDescending = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float EnemySpecialRadius = 1000; //in cm

	UPROPERTY(EditAnywhere, Category = "Shooting")
		float EnemySpecialShootingInterval = 2; //in seconds

	UPROPERTY(EditAnywhere, Category = "Shooting")
		float EnemySpecialChanceToShoot = 8; //in %

	float CurrentAngleInRadians;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);
	void Shoot();
};
