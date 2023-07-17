// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class UEVPP_API AVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()

public:

	AVehiclePawn();

	virtual void Tick(float DeltaTime)override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)override;

	//Throttle/steering
	//�X���b�g���ƃX�e�A�����O
	void ApplyThrottle(float Val);
	void ApplySteering(float Val);

	//Look around
	//���_
	void LookUp(float Val);
	void Turn(float Val);

	//Handbrake
	//�n���h�u���[�L
	void OnHandbrakePressed();
	void OnHandbrakeReleased();

	//Update in air physics
	//�󒆂ł̕������Z
	void UpdateInAirControl(float DeltaTime);

protected:

	//Spring arm that will offset the camera
	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadonly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	//Camera component that will be our viewpoint
	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;
		//float MaxLookUpAngle = 20.f;

	
};
