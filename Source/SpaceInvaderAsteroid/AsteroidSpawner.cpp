// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidSpawner.h"
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"
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

	CurrentTime = 0;
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnAsteroid(DeltaTime);

}

void AAsteroidSpawner::SpawnAsteroid(float DeltaTime)
{
	if (CurrentNumberOfAsteroids < SpawnLimit && CurrentTime >= SpawnInterval) //docelowo zamiast 0 liczba wszystkich asteroid, find actor by class a potem policz ile ich jest
	{
		//choosing location and rotation to spawn
		float randNum1 = rand() % (2 * (MapSize - 100)) - (MapSize - 100); //Random number between -size map and +size of map
		float randNum2 = FMath::RandRange(1, 4);; 	//Random number between 1 and 4 - choose wich quarter

		FRotator SpawnRotation = FRotator(0, randNum1, randNum1);

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

//		FString FloatString = FString::Printf(TEXT("%.2f, %.2f, %.2f"), SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z);
//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);


		//choosing size of asteroid
		int randNum3 = FMath::RandRange(1, 3);

		if (randNum3 == 1) {
			AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation);
			NewAsteroid->SetAsteroidSize(1);
			
			GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Red, "Small");
		}
		else if (randNum3 == 2) {

			AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation);
			NewAsteroid->SetAsteroidSize(2);

			GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Red, "medium");

		}
		else{
			AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation);
			NewAsteroid->SetAsteroidSize(3);

			GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Red, "big");
		}


		CurrentTime = 0;
	}

	CurrentNumberOfAsteroids = AAsteroid::GetNumberOfAsteroids();
	FString FloatString = FString::Printf(TEXT("%d"), CurrentNumberOfAsteroids);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);


	CurrentTime += DeltaTime;
}

int AAsteroid::NumberOfAsteroids = 0;