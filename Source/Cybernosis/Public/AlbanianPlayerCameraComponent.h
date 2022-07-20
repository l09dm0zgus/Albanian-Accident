// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "AlbanianPlayerCameraComponent.generated.h"

UCLASS()
class CYBERNOSIS_API UAlbanianPlayerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:
	UAlbanianPlayerCameraComponent();
	void ZoomIn(float AxisValue);
	void ZoomOut(float AxisValue);
	void PinchZoom(float AxisValue);
private:
	UPROPERTY(EditAnywhere)
	float MaximalZoomDistance = 70.0f;

	UPROPERTY(EditAnywhere)
	float ZoomInAxisValue = -0.5f;

	UPROPERTY(EditAnywhere)
	float ZoomOutAxisValue = 0.5f;

	UPROPERTY(EditAnywhere)
	float MinimalZoomDistance = 20.0f;

};
