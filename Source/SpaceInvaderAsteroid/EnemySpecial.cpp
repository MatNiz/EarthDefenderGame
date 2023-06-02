// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpecial.h"
#include "EnemyProjectile.h"
#include "Math/UnrealMathUtility.h"
#include "Math/RandomStream.h"

// Sets default values
AEnemySpecial::AEnemySpecial()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

}

// Called when the game starts or when spawned
void AEnemySpecial::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle3;
	GetWorldTimerManager().SetTimer(TimerHandle3, this, &AEnemySpecial::Shoot, EnemySpecialShootingInterval, true, 0.0f);

	CurrentAngleInRadians = FMath::DegreesToRadians(CurrentAngle);

}

// Called every frame
void AEnemySpecial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void AEnemySpecial::Move(float DeltaTime)
{
	CurrentAngleInRadians += DeltaTime * EnemySpecialMovementSpeed;
	EnemySpecialRadius -= DeltaTime * EnemySpeedOfDescending;
	
	FVector NewLocation = FVector(FMath::Cos(CurrentAngleInRadians), FMath::Sin(CurrentAngleInRadians), 0.01f) * EnemySpecialRadius;

	SetActorLocation(NewLocation);
}


void AEnemySpecial::Shoot()
{
	float RandomNumber = FMath::FRandRange(0, 100);

	if (EnemySpecialChanceToShoot >= RandomNumber)
	{
		GetWorld()->SpawnActor<AEnemyProjectile>(ProjectileClass, GetActorTransform());
	}
}
