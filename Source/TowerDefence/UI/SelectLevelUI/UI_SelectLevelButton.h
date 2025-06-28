// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_SelectLevelButton.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_SelectLevelButton : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    class UBorder* SelectBorder{};

    UPROPERTY(meta = (BindWidget))
    class UProgressBar* LevelProBar{};

    UPROPERTY(meta = (BindWidget))
    class UButton* SelectLevelButton{};

public:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void SelectLevel();
};
