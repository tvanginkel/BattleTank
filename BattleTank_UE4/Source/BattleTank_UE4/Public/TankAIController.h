// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_UE4_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	//How close the tank can get
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000; 




};
