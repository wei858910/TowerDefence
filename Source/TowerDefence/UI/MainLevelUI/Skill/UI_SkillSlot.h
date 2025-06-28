// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_SkillSlot.generated.h"

class UButton;
class UTextBlock;
class UImage;

UCLASS()
class TOWERDEFENCE_API UUI_SkillSlot : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UImage* SkillIcon{};

    UPROPERTY(meta = (BindWidget))
    UImage* SkillIconCD{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* SkillNumber{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* KeyValueNumber{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* SkillCDValue{};

    UPROPERTY(meta = (BindWidget))
    UButton* ClickButton{};

public:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnClickedWidget();
};
