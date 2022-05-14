// Copyright Epic Games, Inc. All Rights Reserved.


#include "AlbanianAccidentGameModeBase.h"
#include "Public/AlbanianPlayer.h"
#include "Public/PlayerHUD.h"

AAlbanianAccidentGameModeBase::AAlbanianAccidentGameModeBase()
{
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    PrimaryActorTick.bAllowTickOnDedicatedServer = false;

    DefaultPawnClass = AAlbanianPlayer::StaticClass();
    HUDClass = APlayerHUD::StaticClass();
}