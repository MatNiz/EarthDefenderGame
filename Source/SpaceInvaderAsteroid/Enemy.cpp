// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyProjectile.h"
#include "Math/UnrealMathUtility.h"
#include "Math/RandomStream.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle1;
	GetWorldTimerManager().SetTimer(TimerHandle1, this, &AEnemy::Jump, TimeToJump, true, 0.0f);
	FTimerHandle TimerHandle2;
	GetWorldTimerManager().SetTimer(TimerHandle2, this, &AEnemy::ChangeDirections, TimeToChangeDirection, true, 0.0f);
	FTimerHandle TimerHandle3;
	GetWorldTimerManager().SetTimer(TimerHandle3, this, &AEnemy::Shoot, EnemyShootingInterval, true, 0.0f);

	MoveClockwise = 1;
	CurrentAngleInRadians = FMath::DegreesToRadians(CurrentAngle);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void AEnemy::Move(float DeltaTime)
{
	if (MoveClockwise)
	{
		CurrentAngleInRadians += DeltaTime * EnemyMovementSpeed;
	}
	else
	{
		CurrentAngleInRadians -= DeltaTime * EnemyMovementSpeed;
	}

	FVector NewLocation = FVector(FMath::Cos(CurrentAngleInRadians), FMath::Sin(CurrentAngleInRadians), 0.01f) * EnemyRadius;
	SetActorLocation(NewLocation);
}

void AEnemy::Jump()
{
	EnemyRadius -= 100;
}

void AEnemy::ChangeDirections()
{
	MoveClockwise = !MoveClockwise;
}

void AEnemy::Shoot()
{
	float RandomNumber = FMath::FRandRange(0, 100);

	if (EnemyChanceToShoot >= RandomNumber)
	{
		GetWorld()->SpawnActor<AEnemyProjectile>(ProjectileClass, GetActorTransform());
	}
}
