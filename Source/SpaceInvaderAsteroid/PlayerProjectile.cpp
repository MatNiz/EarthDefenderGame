// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProjectile.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Enemy.h"

// Sets default values
APlayerProjectile::APlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent0"));
    StaticMeshComponent->SetupAttachment(RootComponent);
    StaticMeshComponent->BodyInstance.SetCollisionProfileName("Projectile");
    StaticMeshComponent->OnComponentHit.AddDynamic(this, &APlayerProjectile::OnHit);		// set up a notification for when this component hits something
    RootComponent = StaticMeshComponent;
    StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerProjectile::OnOverlapBegin);


    /*
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    StaticMeshComponent->BodyInstance.SetCollisionProfileName("Projectile");
    StaticMeshComponent->OnComponentHit.AddDynamic(this, &APlayerProjectile::OnHit);		// set up a notification for when this component hits something
    RootComponent = StaticMeshComponent;
*/





}

// Called when the game starts or when spawned
void APlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
    CurrentTime = 0;
}

// Called every frame
void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 //   OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);
    Move(DeltaTime);
}

void APlayerProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Red, "uderzenie");

    if (OtherActor && OtherActor->IsA(AEnemy::StaticClass()))
    {
        Destroy();
        OtherActor->Destroy();
    }
}

void APlayerProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Red, "uderzenie");

    if (OtherActor && OtherActor->IsA(AEnemy::StaticClass()))
    {
        Destroy();
        OtherActor->Destroy();
    }

}

void APlayerProjectile::Move(float DeltaTime)
{
    FRotator Rotation = GetActorRotation();
    FVector Location = GetActorLocation();

    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    Location += Direction * DeltaTime * ProjectileSpeed;
    SetActorLocation(Location);

    CurrentTime += DeltaTime;

    if (CurrentTime >= ProjectileLifeTime)
    {
        Destroy();
    }

    //    FString FloatString = FString::Printf(TEXT("%.2f, %.2f, %.2f"), Direction.X, Direction.Y, Direction.Z);
//   GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FloatString);
}