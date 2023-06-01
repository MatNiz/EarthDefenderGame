// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "PlayerProjectile.h"
#include "Enemy.h"
#include "Asteroid.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	CurrentAngle = 0.0f;
	CurrentYRotation = 0.0f;
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayer::Shoot);
	PlayerInputComponent->BindAxis("Move", this, &AMyPlayer::Move);
	PlayerInputComponent->BindAxis("Rotate", this, &AMyPlayer::Rotate);
}

void AMyPlayer::Shoot()
{
	GetWorld()->SpawnActor<APlayerProjectile>(ProjectileClass, GetActorTransform());

	//	FString FloatString = FString::Printf(TEXT("%.2f, %.2f, %.2f"), Direction.X, Direction.Y, Direction.Z);
	//	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);
	//		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Red, "Shoot");
}

void AMyPlayer::Move(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		CurrentAngle += Value * PlayerMovementSpeed;

		FVector NewLocation = FVector(FMath::Cos(CurrentAngle), FMath::Sin(CurrentAngle), 0.1f) * PlayerRadius;

		SetActorLocation(NewLocation);
	}
}

void AMyPlayer::Rotate(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		CurrentYRotation += Value * PlayerRotationSpeed;

		FRotator NewRotation = FRotator(0, CurrentYRotation, 0);

		SetActorRotation(NewRotation);
	}
}

float AMyPlayer::GetRadius()
{
	return PlayerRadius;
}
