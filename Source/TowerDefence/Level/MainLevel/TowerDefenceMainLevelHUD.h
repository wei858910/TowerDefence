// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TowerDefenceMainLevelHUD.generated.h"

class UUI_MainLevel;

UCLASS()
class TOWERDEFENCE_API ATowerDefenceMainLevelHUD : public AHUD
{
	GENERATED_BODY()
public:
	ATowerDefenceMainLevelHUD();
	virtual void BeginPlay() override;

protected:
	TSubclassOf<UUI_MainLevel> UIMainLevelClass;
	class UUI_MainLevel* UIMainLevel{};
};
