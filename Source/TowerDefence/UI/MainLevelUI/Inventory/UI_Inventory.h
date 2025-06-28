// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_Inventory.generated.h"

class UUI_InventorySlot;
class UUniformGridPanel;
/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_Inventory : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UUniformGridPanel* SlotArrayInventory{};

    UPROPERTY(EditDefaultsOnly, Category = UI)
    TSubclassOf<UUI_InventorySlot> InventorySlotClass;

public:
    virtual void NativeConstruct() override;

    void LayoutInventorySlot(int32 ColumNumber, int32 RowNumber);

private:
    TArray<UUI_InventorySlot*> InventorySlotArray{};
};
