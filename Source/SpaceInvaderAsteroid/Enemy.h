// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class SPACEINVADERASTEROID_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

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
		float EnemyMovementSpeed = 0.05;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float TimeToChangeDirection = 3; //in seconds

	UPROPERTY(EditAnywhere, Category = "Movement")
		float TimeToJump = 30; //in seconds

	UPROPERTY(EditAnywhere, Category = "Shooting")
		float EnemyShootingInterval = 2; //in seconds

	UPROPERTY(EditAnywhere, Category = "Shooting")
		int EnemyChanceToShoot = 8; //in %

	float CurrentAngleInRadians;
	float CurrentTimeMove;
	float CurrentTimeShoot;
	float CurrentTimeJump;

	bool MoveClockwise;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);

	void Shoot(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float EnemyRadius = 800; //in cm

};
