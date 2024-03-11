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

}

void AAsteroid::Decay()
{
    if (AsteroidSize == 1)
    {
        Destroy();
    }
    else
    {
        AsteroidSize--;

        double randNum1 = FMath::RandRange(0, 180);
        double randNum2 = FMath::RandRange(180, 360);


        FActorSpawnParameters spawnParams;
        spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FTransform NewTransform = GetActorTransform();
        NewTransform.SetRotation(FQuat::MakeFromEuler(FVector(0.0f, randNum1, 0.0f)));

        AAsteroid* NewAsteroid1 = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, NewTransform, spawnParams);
        NewAsteroid1->SetAsteroidSize(AsteroidSize);


        NewTransform.SetRotation(FQuat::MakeFromEuler(FVector(20, randNum2, 75)));
        
        AAsteroid* NewAsteroid2 = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, NewTransform, spawnParams);
        NewAsteroid2->SetAsteroidSize(AsteroidSize);

        Destroy();
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

    Location.Z = 50;
    SetActorLocation(Location);
}

void AAsteroid::SetMeshSize()
{
    if (AsteroidSize == 1)
    {
        SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
    }
    else if (AsteroidSize == 2)
    {
        SetActorScale3D(FVector(0.7f, 0.7f, 0.7f));
    }
}

int AAsteroid::GetAsteroidSize()
{
    return this->AsteroidSize;
}
void AAsteroid::SetAsteroidSize(int Size)
{
    this->AsteroidSize = Size;
}