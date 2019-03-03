// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


//Called once at the beggining of the game 
void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControllerTank())
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController not possesing pawn"))
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

//Returns ATank of the TankPlayerController
ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


//Aims towards the current position of the Crosshair
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControllerTank()) { return; }

	FVector OutHitLocation;

	if (GetSightRayHitLocation(OutHitLocation))
		GetControllerTank()->AimAt(OutHitLocation);

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
	ColissionParam.AddIgnoredActor(GetControllerTank());

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
