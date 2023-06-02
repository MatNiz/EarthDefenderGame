// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyProjectile.h"
#include "Math/UnrealMathUtility.h"
#include "MyPlayer.h"
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

	CurrentTimeMove = 0;
	CurrentTimeShoot = 0;
	CurrentTimeJump = 0;
	MoveClockwise = 1;
	CurrentAngleInRadians = FMath::DegreesToRadians(CurrentAngle);

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
	Shoot(DeltaTime);
}

void AEnemy::Move(float DeltaTime)
{
	FVector Location = GetActorLocation();

	if (MoveClockwise)
	{
		CurrentAngleInRadians += DeltaTime * EnemyMovementSpeed;
	}
	else
	{
		CurrentAngleInRadians -= DeltaTime * EnemyMovementSpeed;
	}

	if (CurrentTimeMove >= TimeToChangeDirection)
	{
		MoveClockwise = !MoveClockwise;
		CurrentTimeMove = 0;
	}

	if (CurrentTimeJump >= TimeToJump)
	{
		CurrentTimeJump = 0;
		EnemyRadius -= 100;
	}

	FVector NewLocation = FVector(FMath::Cos(CurrentAngleInRadians), FMath::Sin(CurrentAngleInRadians), 0.01f) * EnemyRadius;
	SetActorLocation(NewLocation);

	CurrentTimeMove += DeltaTime;
	CurrentTimeJump += DeltaTime;

//	FString FloatString = FString::Printf(TEXT("%.2f"), CurrentTimeMove);
//	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);

}

void AEnemy::Shoot(float DeltaTime)
{
	if (CurrentTimeShoot >= EnemyShootingInterval)
	{
		int RandomNumber = FMath::RandRange(0, 100);

		if (EnemyChanceToShoot >= RandomNumber)
		{
			GetWorld()->SpawnActor<AEnemyProjectile>(ProjectileClass, GetActorTransform());
		}
		CurrentTimeShoot = 0;
	}

	CurrentTimeShoot += DeltaTime;
}

