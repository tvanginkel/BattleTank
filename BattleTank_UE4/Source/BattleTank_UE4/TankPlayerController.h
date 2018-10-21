// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include


/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_UE4_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLoccation = 0.333333;

	ATank* GetControllerTank() const;



	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};
