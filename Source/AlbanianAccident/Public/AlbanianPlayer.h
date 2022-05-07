// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperSpriteComponent.h"
#include "AlbanianPlayerMovementComponent.h"
#include "AlbanianPlayerCameraComponent.h"
#include "HealthComponent.h"
#include "EyesLightComponent.h"
#include "PaperFlipbookComponent.h"
#include "AlbanianPlayer.generated.h"

UCLASS()
class ALBANIANACCIDENT_API AAlbanianPlayer : public APawn
{
	GENERATED_BODY()

public:
	AAlbanianPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
	UAlbanianPlayerMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere)
	UAlbanianPlayerCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UPaperFlipbookComponent* FlipbookComponent;

	UPROPERTY(EditAnywhere)
	UPaperFlipbook* FistWeaponAnimation;

	UPROPERTY(EditAnywhere)
	UPaperFlipbook* SecondWeaponAnimation;

	UPROPERTY(EditAnywhere)
	UPaperFlipbook* ThirdWeaponAnimation;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	UEyesLightComponent* EyesLightComponent;

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void CreateAndSetupSpringArmComponent();
	void CreateAndSetupCameraComponent();
	void CreateAndSetupMovementComponent();
	void CreateAndSetupFlipbookComponent();
	void CreateAndSetupEyesLightComponent();
	void CreateAndSetupHealthComponent();
	void SetupLightFlare();
	void SetupFirstEyeLight();
	void SetupSecondEyeLight();
	void RollActor(float Angle);
	void ChooseFistWeapon();
	void ChooseSecondWeapon();
	void ChooseThirdWeapon();
};
