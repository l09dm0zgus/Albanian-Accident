// Fill out your copyright notice in the Description page of Project Settings.


#include "AlbanianPlayerCameraComponent.h"

UAlbanianPlayerCameraComponent::UAlbanianPlayerCameraComponent()
{

}

void UAlbanianPlayerCameraComponent::ZoomIn(float AxisValue)
{
	if (GetRelativeLocation().Z >= MinimalZoomDistance)
	{
		AddRelativeLocation(FVector(0.0f, 0.0f, AxisValue));
	}
}

void UAlbanianPlayerCameraComponent::ZoomOut(float AxisValue)
{
	if (GetRelativeLocation().Z <= MaximalZoomDistance)
	{
		AddRelativeLocation(FVector(0.0f,0.0, AxisValue));
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




