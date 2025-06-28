// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenceMainLevelHUD.h"

#include "Blueprint/UserWidget.h"
#include "TowerDefence/UI/MainLevelUI/UI_MainLevel.h"

ATowerDefenceMainLevelHUD::ATowerDefenceMainLevelHUD()
{
    ConstructorHelpers::FClassFinder<UUI_MainLevel> UIMainLevelBPClass(TEXT(""));
    UIMainLevelClass = UIMainLevelBPClass.Class;
}

void ATowerDefenceMainLevelHUD::BeginPlay()
{
    Super::BeginPlay();
    if (UIMainLevelClass)
    {
        UIMainLevel = CreateWidget<UUI_MainLevel>(GetWorld(), UIMainLevelClass);
        UIMainLevel->AddToViewport();
    }
}
