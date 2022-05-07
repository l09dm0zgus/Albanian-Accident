// Fill out your copyright notice in the Description page of Project Settings.


#include "AlbanianPlayerMovementComponent.h"

void UAlbanianPlayerMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * Speed;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
        if (Hit.IsValidBlockingHit())
        {
            StopMovementImmediately();
        }
    }
      
}

void UAlbanianPlayerMovementComponent::Turn(float AxisValue)
{
    FRotator Rotator = UpdatedComponent->GetComponentRotation();
    Rotator.Yaw += AxisValue;
    UpdatedComponent->SetRelativeRotation(Rotator);
}

