// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	double SlippageSpeed = FVector::DotProduct(GetRightVector(), GetPhysicsAngularVelocityInDegrees());
	

	FVector CorrectionAcceleration = SlippageSpeed / DeltaTime * GetRightVector();
	FVector CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; //There are two tracks

	UE_LOG(LogTemp, Warning, TEXT("Track: %s,Velocity: %f"), *GetName(), *CorrectionAcceleration.ToString())
	//TankRoot->AddForce(CorrectionForce);

}

void UTankTrack::SetThrottle(float Throttle)
{
	//TODO clamp values so player can't over-drive
	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
}


