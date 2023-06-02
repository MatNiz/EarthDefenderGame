// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyProjectile.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemyProjectile::AEnemyProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void AEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();

    CurrentTime = 0;
	
}

// Called every frame
void AEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Move(DeltaTime);

}

void AEnemyProjectile::Move(float DeltaTime)
{
    FVector Location = GetActorLocation();
    FVector DirectionToOrigin = FVector::ZeroVector - Location;
    FVector Direction = UKismetMathLibrary::Normal(DirectionToOrigin);
    
    Location += Direction * DeltaTime * EnemyProjectileSpeed;
    SetActorLocation(Location);

    CurrentTime += DeltaTime;

}