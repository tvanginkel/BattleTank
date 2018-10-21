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

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


