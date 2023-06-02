// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidSpawner.h"
#include "Asteroid.h"

// Sets default values
AAsteroidSpawner::AAsteroidSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < NumberOfBeginingAsteroids; i++) SpawnAsteroid();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAsteroidSpawner::SpawnAsteroid, SpawnInterval, true, 0.0f);
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAsteroidSpawner::SpawnAsteroid()
{
	//choosing location and rotation to spawn
	float randNum1 = rand() % (2 * (MapSize - 100)) - (MapSize - 100); //Random number between -size map and +size of map
	float randNum2 = FMath::RandRange(1, 4);; 	//Random number between 1 and 4 - choose wich quarter of board

	FRotator SpawnRotation = FRotator(0, randNum1, 0);

	FVector SpawnLocation;

	if (randNum2 == 1) {
		SpawnLocation = FVector((MapSize-100), randNum1, 50);
	}
	else if (randNum2 == 2) {
		SpawnLocation = FVector(-(MapSize - 100), randNum1, 50);
	}
	else if (randNum2 == 3) {
		SpawnLocation = FVector(randNum1, -(MapSize - 100), 50);
	}
	else {
		SpawnLocation = FVector(randNum1, (MapSize - 100), 50);
	}

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	//choosing size of asteroid
	int randNum3 = FMath::RandRange(1, 3);

	FTransform NewTransform = GetActorTransform();
//	NewTransform.SetRotation(FQuat::MakeFromEuler(SpawnRotation));

	if (randNum3 == 1) {
		AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation, spawnParams);
		NewAsteroid->SetAsteroidSize(1);
	}
	else if (randNum3 == 2) {
		AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation, spawnParams);
		NewAsteroid->SetAsteroidSize(2);
	}
	else{
		AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation, spawnParams);
		NewAsteroid->SetAsteroidSize(3);
	}
	
//	FString FloatString = FString::Printf(TEXT("%d"), CurrentNumberOfAsteroids);
//	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);

}