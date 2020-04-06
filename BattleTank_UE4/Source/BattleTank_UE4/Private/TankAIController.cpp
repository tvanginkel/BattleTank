// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h" //Include to use GetWorld()

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	UTankAimingComponent* AIAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(PlayerTank && AIAimingComponent)) { return; }
	
	MoveToActor(PlayerTank, AcceptanceRadius);
	AIAimingComponent->AimAt(PlayerTank->GetActorLocation());
	

	AIAimingComponent->Fire(); 
	

}


