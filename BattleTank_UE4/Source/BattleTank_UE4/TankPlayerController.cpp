// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControllerTank())
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController not possesing pawn"))
	else
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing: %s"), *(GetControllerTank()->GetName()))
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControllerTank()) { return; }

	FVector OutHitLocation;

	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *OutHitLocation.ToString());
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
