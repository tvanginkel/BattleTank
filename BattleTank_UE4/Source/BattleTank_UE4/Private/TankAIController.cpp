// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//Protect GetControllerTank()
	if(!GetControllerTank())
		UE_LOG(LogTemp, Error, TEXT("AI not possesing tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI tank name: %s"), *GetControllerTank()->GetName())

	//Protect GetPlayerTank()
	if (!GetPlayerTank())
		UE_LOG(LogTemp, Error, TEXT("Player not possesing tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("Player tank name: %s"), *GetPlayerTank()->GetName())
}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

