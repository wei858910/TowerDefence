// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TowerDefenceSelectLevelGameMode.generated.h"

UCLASS()
class TOWERDEFENCE_API ATowerDefenceSelectLevelGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    ATowerDefenceSelectLevelGameMode();

protected:
    virtual void BeginPlay() override;
};
