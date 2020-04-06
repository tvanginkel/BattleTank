// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

//Called once at the beggining of the game 
void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!ensure(GetPawn())) { return; }

	UTankAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}		
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

//Aims towards the current position of the Crosshair
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetPawn())) { return; }
	UTankAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	FVector OutHitLocation;
	if (!ensure(AimingComponent)) { return; }

	if (GetSightRayHitLocation(OutHitLocation))
		AimingComponent->AimAt(OutHitLocation);

}

//Returns true if it hits landscape and changes the value of OutHitLocation.
//Otherwise returns false
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Get Crosshair position in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLoccation );

	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		if (GetLookVectorHitLocation(OutHitLocation, LookDirection))
			return true;
	}

	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& OutHitLocation, FVector LookDirection) const
{
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
	FHitResult HitResult;
	FCollisionQueryParams ColissionParam;
	ColissionParam.AddIgnoredActor(GetPawn());

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, ColissionParam))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;

}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}
