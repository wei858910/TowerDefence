// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_MainLevel.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_MainLevel : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta=(bindWidget))
    class UUI_GameMenuSystem* UIGameMenuSystem{};

    UPROPERTY(meta=(bindWidget))
    class UUI_GameInfoPrintSystem* UIGameInfoPrintSystem{};

    UPROPERTY(meta=(bindWidget))
    class UUI_MiniMapSystem* UIMiniMapSystem{};

    UPROPERTY(meta=(bindWidget))
    class UUI_MissionSystem* UIMissionSystem{};

    UPROPERTY(meta=(bindWidget))
    class UUI_PlayerSkillSystem* UIPlayerSkillSystem{};

    UPROPERTY(meta=(bindWidget))
    class UUI_RucksackSystem* UIRucksackSystem{};

    UPROPERTY(meta=(bindWidget))
    class UUI_ToolbarSystem* UIToolbarSystem{};

public:
    virtual void NativeConstruct() override;
};
