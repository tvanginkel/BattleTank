// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include


/**
 * 
 */
UCLASS()
class BATTLETANK_UE4_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATank* GetControllerTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

};
