// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_GameMenuSystem.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_GameMenuSystem : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(bindWidget))
	UButton* ReturnGameButton{};

	UPROPERTY(meta=(bindWidget))
	UButton* SaveGameButton{};
	
	UPROPERTY(meta=(bindWidget))
	UButton* GameSettingButton{};
	
	UPROPERTY(meta=(bindWidget))
	UButton* QuitGameButton{};

public:
	
	virtual void NativeConstruct() override;

	UFUNCTION()
	void ReturnGame();

	UFUNCTION()
	void SaveGame();

	UFUNCTION()
	void GameSetting();

	UFUNCTION()
	void QuitGame();
};
