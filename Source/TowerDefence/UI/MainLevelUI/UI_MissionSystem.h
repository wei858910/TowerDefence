// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_MissionSystem.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class TOWERDEFENCE_API UUI_MissionSystem : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ConditionBase{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ConditionA{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ConditionB{};

    UPROPERTY(meta = (BindWidget))
    UButton* ConditionButton{};

public:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void Condition();
};
