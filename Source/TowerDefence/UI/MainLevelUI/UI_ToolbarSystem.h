// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_ToolbarSystem.generated.h"

class UProgressBar;
class UTextBlock;

UCLASS()
class TOWERDEFENCE_API UUI_ToolbarSystem : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UTextBlock* GameGlob{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TowerDeathNumber{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* GameCount{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* KillSoldier{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* GameLevelRemainingQuantity{};

    UPROPERTY(meta = (BindWidget))
    UProgressBar* RemainingEnemyBar{};

public:
    virtual void NativeConstruct() override;
};
