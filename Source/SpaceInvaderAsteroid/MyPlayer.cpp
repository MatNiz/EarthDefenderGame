// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "PlayerProjectile.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

//	ProjectileClass = PlayerProjectile;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	CurrentAngle = 0.0f;
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
}

void AMyPlayer::Shoot()
{
	FTransform MyTransform = GetActorTransform();
	MyTransform.SetLocation(MyTransform.GetLocation() + FVector(0, 0, 30));
	GetWorld()->SpawnActor<APlayerProjectile>(ProjectileClass, MyTransform);
}

void AMyPlayer::Move(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		CurrentAngle += Value * PlayerMovementSpeed;

		FVector NewLocation = FVector(FMath::Cos(CurrentAngle), FMath::Sin(CurrentAngle), 0.1f) * PlayerRadius;
		SetActorLocation(NewLocation);

		FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(FVector::ZeroVector, GetActorLocation());
		SetActorRotation(NewRotation);
	}
}
