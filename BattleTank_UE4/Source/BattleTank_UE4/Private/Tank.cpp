// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	if (!ensure(ProjectileBlueprint))
	{
		return;
		UE_LOG(LogTemp, Error, TEXT("Tank has no projectile blueprint"))
	}

}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{
		if (!ensure(ProjectileBlueprint)) { return; }
		//Spawn projectile at soket location
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			 ProjectileBlueprint,
			 Barrel->GetSocketLocation(FName("Projectile")),
			 Barrel->GetSocketRotation(FName("Projectile")));
		
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
