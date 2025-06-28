// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_RucksackSystem.generated.h"

class UUI_Inventory;
/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_RucksackSystem : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    UUI_Inventory* Inventory{};

public:
    virtual void NativeConstruct() override;
};
