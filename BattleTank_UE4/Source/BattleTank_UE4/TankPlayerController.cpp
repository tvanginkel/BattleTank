// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


//Called once at the beggining of the game 
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
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *OutHitLocation.ToString());
	}

}

//Returns true if it hits landscape and changes the value of OutHitLocation.
//Otherwise returns false
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	//Get Crosshair position in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLoccation );


	return true;
}
