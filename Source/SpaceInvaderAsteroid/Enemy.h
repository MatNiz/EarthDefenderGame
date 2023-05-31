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

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AEnemyProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AMyPlayer> MyPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float Radius = 800; //in cm

	UPROPERTY(EditAnywhere, Category = "Movement")
		float CurrentAngle = 0; //in degrees

	float CurrentAngleInRadians;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed = 0.1;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float TimeToChangeDirection = 20; //in seconds



	UPROPERTY(EditAnywhere, Category = "Shooting")
		float ShootingInterval = 1; //in seconds

	UPROPERTY(EditAnywhere, Category = "Shooting")
		float ChanceToShoot = 20; //in %

	float CurrentTimeMove;
	float CurrentTimeShoot;

	bool MoveClockwise;

	FRandomStream RandStream;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);

	void Shoot(float DeltaTime);

};
