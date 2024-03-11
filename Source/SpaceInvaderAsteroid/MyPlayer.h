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



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(EditDefaultsOnly, Category = "References")
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditDefaultsOnly, Category = "References")
		TSubclassOf<class APlayerProjectile> ProjectileClass;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float MovementRadius;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		float MovementSpeed;

	float CurrentAngle;


	void Shoot();
	void Move(float Value);
};
