// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_UE4_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//Sets throttle between 1 and -1
	UFUNCTION(BlueprintCallable)
	void SetThrottle(float Throttle);

	//Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 150000000.0; // Assume tank mass is 60,000 kg and acceleration is 1g
	
private:
	
	UTankTrack();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
