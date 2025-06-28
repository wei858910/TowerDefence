// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_GameMenuSystem.h"

#include "Components/Button.h"

void UUI_GameMenuSystem::NativeConstruct()
{
    Super::NativeConstruct();

    if (ReturnGameButton)
    {
        ReturnGameButton->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::ReturnGame);
    }

    if (SaveGameButton)
    {
        SaveGameButton->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::SaveGame);
    }

    if (GameSettingButton)
    {
        GameSettingButton->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::GameSetting);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::QuitGame);
    }
}

void UUI_GameMenuSystem::ReturnGame()
{
}

void UUI_GameMenuSystem::SaveGame()
{
}

void UUI_GameMenuSystem::GameSetting()
{
}

void UUI_GameMenuSystem::QuitGame()
{
}
