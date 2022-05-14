// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class ALBANIANACCIDENT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
public:
	APlayerHUD();
	void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	TSubclassOf<UUserWidget> PlayerWidget;

	UUserWidget* CurrentWidget;
};
