// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"

// Sets default values

AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;

}


// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);

}



void AAsteroid::Move(float DeltaTime)
{

    FRotator Rotation = GetActorRotation();
    FVector Location = GetActorLocation();

    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    Location += Direction * DeltaTime * AsteroidSpeed;
    

    if (Location.X >= MapSize) Location.X = -(MapSize-100); if (Location.X <= -MapSize) Location.X = (MapSize - 100);
    if (Location.Y >= MapSize) Location.Y = -(MapSize - 100); if (Location.Y <= -MapSize) Location.Y = (MapSize - 100);

    SetActorLocation(Location);
}

