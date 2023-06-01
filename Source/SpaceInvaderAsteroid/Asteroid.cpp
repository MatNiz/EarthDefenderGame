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

    SetMeshSize();
    Move(DeltaTime);

    CurrentTime += DeltaTime;

    if (CurrentTime >= AsteroidLifeTime)
    {
        Decay();
        CurrentTime = 0;
    }
}

void AAsteroid::Decay()
{
    FVector Location = GetActorLocation();

    float randNum1 = FMath::RandRange(0, 360);
    float randNum2 = FMath::RandRange(0, 360);

    FRotator SpawnRotation1 = FRotator(0, randNum1, randNum2);
    FRotator SpawnRotation2 = FRotator(0, randNum2, randNum1);

    if (AsteroidSize == 1)
    {
        Destroy();
    }
    else
    {
        AsteroidSize--;

        AAsteroid* NewAsteroid1 = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, Location, SpawnRotation1);
        NewAsteroid1->SetAsteroidSize(AsteroidSize);
        AAsteroid* NewAsteroid2 = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, Location, SpawnRotation1);
        NewAsteroid2->SetAsteroidSize(AsteroidSize);
    }
}

void AAsteroid::Move(float DeltaTime)
{

    FRotator Rotation = GetActorRotation();
    FVector Location = GetActorLocation();

    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    Location += Direction * DeltaTime * AsteroidSpeed;


    if (Location.X >= MapSize) Location.X = -(MapSize - 100); if (Location.X <= -MapSize) Location.X = (MapSize - 100);
    if (Location.Y >= MapSize) Location.Y = -(MapSize - 100); if (Location.Y <= -MapSize) Location.Y = (MapSize - 100);

    SetActorLocation(Location);
}


void AAsteroid::SetMeshSize()
{
    if (AsteroidSize == 1)
    {
        StaticMeshComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    }
    else if (AsteroidSize == 2)
    {
        StaticMeshComponent->SetRelativeScale3D(FVector(0.7f, 0.7f, 0.7f));
    }
}

/*




*/