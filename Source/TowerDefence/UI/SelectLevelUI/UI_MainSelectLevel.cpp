// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MainSelectLevel.h"

#include "UI_SelectLevelButton.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"

void UUI_MainSelectLevel::ReturnMenu()
{
    UGameplayStatics::OpenLevel(GetWorld(), "HallMap");
}

void UUI_MainSelectLevel::NativeConstruct()
{
    Super::NativeConstruct();
    InitAllLevelButtons();

    if (ReturnMenuButton)
    {
        ReturnMenuButton->OnClicked.AddDynamic(this, &UUI_MainSelectLevel::ReturnMenu);
    }
}

void UUI_MainSelectLevel::InitAllLevelButtons()
{
    if (SelectMap)
    {
        for (TArray<UPanelSlot*> PanelSlots = SelectMap->GetSlots(); const UPanelSlot* PanelSlot : PanelSlots)
        {
            if (UUI_SelectLevelButton* SelectLevelButton = Cast<UUI_SelectLevelButton>(PanelSlot->Content))
            {
                AllSelectLevelButtons.Add(SelectLevelButton);
            }
        }
    }
}
