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

	MoveClockwise = 1;

	CurrentAngleInRadians = FMath::DegreesToRadians(CurrentAngle);

//	FRandomStream RandStream;
	
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

//	FString FloatString = FString::Printf(TEXT("%.2f"), CurrentAngleInRadians);
//	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);


	if (MoveClockwise)
	{
		CurrentAngleInRadians += DeltaTime * MovementSpeed;
	}
	else
	{
		CurrentAngleInRadians -= DeltaTime * MovementSpeed;
	}

	if (CurrentTimeMove >= TimeToChangeDirection)
	{
		MoveClockwise = !MoveClockwise;
		CurrentTimeMove = 0;
		Radius -= 100;

		if (Radius <= 200) // MyPlayer.GetDefaultObject()->GetRadius()
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Koniec gry");

		}
	}

	FVector NewLocation = FVector(FMath::Cos(CurrentAngleInRadians), FMath::Sin(CurrentAngleInRadians), 0.1f) * Radius;
	SetActorLocation(NewLocation);

	CurrentTimeMove += DeltaTime;

//	FString FloatString = FString::Printf(TEXT("%.2f"), CurrentTimeMove);
//	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);

}

void AEnemy::Shoot(float DeltaTime)
{

	if (CurrentTimeShoot >= ShootingInterval)
	{
		float MinValue = 0.0f;
		float MaxValue = 100.0f;

		float RandomNumber = RandStream.FRandRange(MinValue, MaxValue);

//		FString FloatString = FString::Printf(TEXT("%.2f"), RandomNumber);
//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);

		if (ChanceToShoot >= RandomNumber)
		{
			GetWorld()->SpawnActor<AEnemyProjectile>(ProjectileClass, GetActorTransform());
		}

		CurrentTimeShoot = 0;
	}

	CurrentTimeShoot += DeltaTime;
}

