// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SelectLevelButton.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UUI_SelectLevelButton::NativeConstruct()
{
    Super::NativeConstruct();

    if (SelectLevelButton)
    {
        SelectLevelButton->OnClicked.AddDynamic(this, &UUI_SelectLevelButton::SelectLevel);
    }
}

void UUI_SelectLevelButton::SelectLevel()
{
    UGameplayStatics::OpenLevel(GetWorld(), "MainLevel");
}
