// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_MainHall.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API UUI_MainHall : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(meta = (BindWidget))
    class UUI_HallMenuSystem* HallMenuSystem{};

protected:
    virtual void NativeConstruct() override;
};
