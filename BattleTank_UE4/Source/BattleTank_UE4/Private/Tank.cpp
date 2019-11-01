// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("MONKEY: Tank Constructor"))

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	if (!ProjectileBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank has no projectile blueprint"))
	}
	UE_LOG(LogTemp, Warning, TEXT("MONKEY: Tank BeginPlay()"))
}


// Called to bind functionality to input

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded)
	{
		if (!ProjectileBlueprint) { return; }
		//Spawn projectile at soket location
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			 ProjectileBlueprint,
			 Barrel->GetSocketLocation(FName("Projectile")),
			 Barrel->GetSocketRotation(FName("Projectile")));
		
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
