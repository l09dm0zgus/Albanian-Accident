// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Blueprint/UserWidget.h"
APlayerHUD::APlayerHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> PlayerHUDObject(TEXT("/Game/HUD/PlayerHUD"));
   PlayerWidget = PlayerHUDObject.Class;
}
void APlayerHUD::BeginPlay()
{
    Super::BeginPlay();
    if (PlayerWidget != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerWidget);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}


