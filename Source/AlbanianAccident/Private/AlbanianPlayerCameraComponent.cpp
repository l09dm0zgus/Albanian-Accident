// Fill out your copyright notice in the Description page of Project Settings.


#include "AlbanianPlayerCameraComponent.h"

UAlbanianPlayerCameraComponent::UAlbanianPlayerCameraComponent()
{
	SetRelativeRotation(FRotator(0.0f, 90.0f, -45.0f));
	SetRelativeLocation(FVector(0.0f, -45.0f, 0.0f));
}

void UAlbanianPlayerCameraComponent::ZoomIn(float AxisValue)
{
	ChangeNumberSignToZero(MinimalZoomDistance);
	if (GetRelativeLocation().Y <= MinimalZoomDistance)
	{
		AddRelativeLocation(FVector(0.0f, AxisValue, 0.0f));
	}
}

void UAlbanianPlayerCameraComponent::ZoomOut(float AxisValue)
{
	ChangeNumberSignToZero(MaximalZoomDistance);
	if (GetRelativeLocation().Y >= MaximalZoomDistance)
	{
		AddRelativeLocation(FVector(0.0f, AxisValue, 0.0f));
	}
}

void UAlbanianPlayerCameraComponent::PinchZoom(float AxisValue)
{
	if (AxisValue != 1.0)
	{
		if (AxisValue < 1.0f)
		{
			ZoomOut(ZoomOutAxisValue);
		}
		if (AxisValue > 1.0f)
		{
			ZoomIn(ZoomInAxisValue);
		}
	}
	
}



void UAlbanianPlayerCameraComponent::ChangeNumberSignToZero(float &number)
{
	if (number > 0.0f)
	{
		number *= -1.0f;
	}
}
