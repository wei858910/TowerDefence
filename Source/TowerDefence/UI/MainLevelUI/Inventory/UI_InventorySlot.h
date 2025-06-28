// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_InventorySlot.generated.h"

class UButton;
class UTextBlock;
class UImage;

UCLASS()
class TOWERDEFENCE_API UUI_InventorySlot : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UImage* TowerIcon{};

    UPROPERTY(meta = (BindWidget))
    UImage* TowerCD{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TowerPrepareBuildingNumber{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TowerCompleteBuildingNumber{};

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TowerCDValue{};

    UPROPERTY(meta = (BindWidget))
    UButton* TowerInventorySlotButton{};

public:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnClickedWidget();
};
