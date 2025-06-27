// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefencePlayerController.h"
#include "SimpleScreenMove/ScreenMoveUtils.h"

ATowerDefencePlayerController::ATowerDefencePlayerController()
{
    bShowMouseCursor = true;
}

void ATowerDefencePlayerController::BeginPlay()
{
    Super::BeginPlay();
    LimitMousePosition();
}

void ATowerDefencePlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    FScreenMoveUtils::ListenScreenMove(this, ScreenMoveSpeed);
}

void ATowerDefencePlayerController::LimitMousePosition()
{
    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
    InputMode.SetHideCursorDuringCapture(false);
    SetInputMode(InputMode);
}
