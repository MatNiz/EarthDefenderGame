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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ProjectileClass")
		TSubclassOf<class APlayerProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		float PlayerRadius = 200; //in cm

	UPROPERTY(EditAnywhere, Category = "Parameters")
		float PlayerMovementSpeed = 0.02;

	float CurrentAngle;

	void Shoot();
	void Move(float Value);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
