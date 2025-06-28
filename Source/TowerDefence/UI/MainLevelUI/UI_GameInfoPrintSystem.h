// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_GameInfoPrintSystem.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_GameInfoPrintSystem : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TowerDefenceGameLog{};

public:
	virtual void NativeConstruct() override;
};
