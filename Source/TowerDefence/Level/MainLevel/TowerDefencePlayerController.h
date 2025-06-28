// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TowerDefencePlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class TOWERDEFENCE_API ATowerDefencePlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ATowerDefencePlayerController();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    void MouseWheelAxis(FInputActionValue& ActionValue);
    
    virtual void SetupInputComponent() override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Screen", meta=(AllowPrivateAccess="true"))
    float ScreenMoveSpeed = 50.f;

    UPROPERTY(EditdefaultsOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UInputMappingContext> IMC_TowerDefence;
    
    UPROPERTY(EditdefaultsOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UInputAction> IA_MouseWheel;

protected:
    // 限制鼠标在窗口内移动
    void LimitMousePosition();
};
