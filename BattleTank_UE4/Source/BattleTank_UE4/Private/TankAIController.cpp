// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h" //Include to use GetWorld()

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* AITank = Cast<ATank>(GetPawn());
	
	if (PlayerTank && AITank)
	{
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire(); 
	}

}


