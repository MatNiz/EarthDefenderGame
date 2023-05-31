// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

UCLASS()
class SPACEINVADERASTEROID_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class APlayerProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;


	UPROPERTY(EditAnywhere, Category = "Movement")
		float Radius = 400; //in cm

	float CurrentAngle;
	float CurrentYRotation;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed = 0.02;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float RotationSpeed = 1;


	void Shoot();

	void Move(float Value);
	void Rotate(float Value);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float GetRadius();


};
