// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Inventory.h"

#include "UI_InventorySlot.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"

void UUI_Inventory::NativeConstruct()
{
    Super::NativeConstruct();

    LayoutInventorySlot(3, 7);
}

void UUI_Inventory::LayoutInventorySlot(const int32 ColumNumber, const int32 RowNumber)
{
    if (InventorySlotClass)
    {
        for (int32 Row = 0; Row < RowNumber; Row++)
        {
            for (int32 Colum = 0; Colum < ColumNumber; Colum++)
            {
                if (auto InventorySlot = CreateWidget<UUI_InventorySlot>(GetWorld(), InventorySlotClass))
                {
                    InventorySlotArray.Add(InventorySlot);
                    if (UUniformGridSlot* GridSlot = SlotArrayInventory->AddChildToUniformGrid(InventorySlot))
                    {
                        GridSlot->SetColumn(Colum);
                        GridSlot->SetRow(Row);
                        GridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
                        GridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
                    }
                }
            }
        }
    }
}
