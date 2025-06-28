// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MissionSystem.h"

#include "Components/Button.h"

void UUI_MissionSystem::NativeConstruct()
{
    Super::NativeConstruct();

    if (ConditionButton)
    {
        ConditionButton->OnClicked.AddDynamic(this, &UUI_MissionSystem::Condition);
    }
}

void UUI_MissionSystem::Condition()
{
}
