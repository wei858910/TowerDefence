// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_PlayerSkillSystem.generated.h"

class UUI_SkillSlot;
/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_PlayerSkillSystem : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* FreezeSkill{};

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* ExplosionSkill{};

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* RecoverySkill{};
	
	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* RecoveryMainTowerSkill{};

public:
	virtual void NativeConstruct() override;

private:
	FKey FreezeSkillKey;
	FKey ExplosionSkillKey;
	FKey RecoverySkillKey;
	FKey RecoveryMainTowerSkillKey;
};
