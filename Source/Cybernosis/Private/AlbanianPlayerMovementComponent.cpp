// Fill out your copyright notice in the Description page of Project Settings.


#include "AlbanianPlayerMovementComponent.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

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
    FVector MouseLocation, MouseDirection;
    FVector ActorLocation = UpdatedComponent->GetComponentLocation();
    UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
    FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(ActorLocation, MouseLocation);
    UpdatedComponent->SetRelativeRotation(FRotator(0.0f,NewRotation.Yaw,90.0f));
}

