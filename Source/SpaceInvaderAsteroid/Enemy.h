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


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Jump();
	void ChangeDirections();
	void Shoot();


private:
	UPROPERTY(EditDefaultsOnly, Category = "References")
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditDefaultsOnly, Category = "References")
		TSubclassOf<class AEnemyProjectile> ProjectileClass;
	UPROPERTY(EditInstanceOnly, Category = "Parameters")
		float StartingAngleInDegrees = 0;
	UPROPERTY(EditInstanceOnly, Category = "Parameters")
		float StartngRadius = 800;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float MovementSpeed = 0.05;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float SecondsToChangeDirection = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float SecondsToJump = 30;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float ShootingIntervalInSeconds = 2;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float PercentChanceToShoot = 8;

	float CurrentAngleInRadians;
	bool MoveClockwise;


	void Move(float DeltaTime);

};
