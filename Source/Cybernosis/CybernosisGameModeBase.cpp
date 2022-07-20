// Copyright Epic Games, Inc. All Rights Reserved.


#include "CybernosisGameModeBase.h"
#include "Public/AlbanianPlayer.h"
#include "Public/PlayerHUD.h"

ACybernosisGameModeBase::ACybernosisGameModeBase()
{
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    PrimaryActorTick.bAllowTickOnDedicatedServer = false;

    DefaultPawnClass = AAlbanianPlayer::StaticClass();
    HUDClass = APlayerHUD::StaticClass();
}
