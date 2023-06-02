// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProjectile.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Enemy.h"

// Sets default values
APlayerProjectile::APlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
   
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void APlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
    CurrentTime = 0;
}

// Called every frame
void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Move(DeltaTime);
}

void APlayerProjectile::Move(float DeltaTime)
{
    FRotator Rotation = GetActorRotation();
    FVector Location = GetActorLocation();

    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    Location += Direction * DeltaTime * ProjectileSpeed;
    SetActorLocation(Location);

    CurrentTime += DeltaTime;

    if (CurrentTime >= ProjectileLifeTime)
    {
        Destroy();
    }
}
