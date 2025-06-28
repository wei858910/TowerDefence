// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_MainSelectLevel.generated.h"


class UCanvasPanel;
class UUI_SelectLevelButton;
class UButton;

UCLASS()
class TOWERDEFENCE_API UUI_MainSelectLevel : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UButton* ReturnMenuButton{};

    UPROPERTY(meta = (BindWidget))
    UCanvasPanel* SelectMap{};

public:
    UFUNCTION()
    void ReturnMenu();
    
    virtual void NativeConstruct() override;

protected:
    void InitAllLevelButtons();

private:
    TArray<UUI_SelectLevelButton*> AllSelectLevelButtons{};
};
