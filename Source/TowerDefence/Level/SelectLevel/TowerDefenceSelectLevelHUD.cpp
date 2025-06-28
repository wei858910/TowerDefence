// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenceSelectLevelHUD.h"

#include "Blueprint/UserWidget.h"
#include "TowerDefence/UI/SelectLevelUI/UI_MainSelectLevel.h"

ATowerDefenceSelectLevelHUD::ATowerDefenceSelectLevelHUD()
{
    const ConstructorHelpers::FClassFinder<UUI_MainSelectLevel> MainSelectLevelBPClass(TEXT("/Game/UI/SelectLevel/UIBP_MainSelectLevel.UIBP_MainSelectLevel_C"));
    UIMainSelectLevelClass = MainSelectLevelBPClass.Class;
}

void ATowerDefenceSelectLevelHUD::BeginPlay()
{
    Super::BeginPlay();
    if (UIMainSelectLevelClass)
    {
        UIMainSelectLevel = CreateWidget<UUI_MainSelectLevel>(GetWorld(), UIMainSelectLevelClass);
        UIMainSelectLevel->AddToViewport();
    }
}
