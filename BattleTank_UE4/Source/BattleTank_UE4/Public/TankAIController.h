// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank.h" //Include to use ATank class
#include "Engine/World.h" //Include to use GetWorld()
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_UE4_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	
	ATank* GetControllerTank() const;
	ATank* GetPlayerTank() const;

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

};
