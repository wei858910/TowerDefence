// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerDefence/UI/TowerDefenceHUDBase.h"
#include "TowerDefenceHallHUD.generated.h"

class UUI_MainHall;

UCLASS()
class TOWERDEFENCE_API ATowerDefenceHallHUD : public ATowerDefenceHUDBase
{
    GENERATED_BODY()

public:
    ATowerDefenceHallHUD();
    virtual void BeginPlay() override;

private:
    TSubclassOf<UUserWidget> UIMainHallClass{};

    UPROPERTY()
    UUI_MainHall* UIMainHall{};
};
