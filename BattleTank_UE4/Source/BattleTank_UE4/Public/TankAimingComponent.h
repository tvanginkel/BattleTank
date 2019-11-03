// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel; //Forward Declaration
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_UE4_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

/*Variables*/
public:	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 15000;

private:

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;


/*Functions*/
public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
		
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EState State = EState::Locked;

private:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveBarrelTowards(FVector AimDirection);
};
