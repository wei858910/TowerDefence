// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenceHallHUD.h"

#include "Blueprint/UserWidget.h"
#include "TowerDefence/UI/HallLevelUI/UI_MainHall.h"

ATowerDefenceHallHUD::ATowerDefenceHallHUD()
{
    const ConstructorHelpers::FClassFinder<UUI_MainHall> UI_MainHallBPRef(TEXT("/Game/UI/HallLevel/UIBP_MainHall.UIBP_MainHall_C"));
    UIMainHallClass = UI_MainHallBPRef.Class;
}

void ATowerDefenceHallHUD::BeginPlay()
{
    Super::BeginPlay();
    if (UIMainHallClass)
    {
        UIMainHall = CreateWidget<UUI_MainHall>(GetWorld(), UIMainHallClass);
        UIMainHall->AddToViewport();
    }
}
