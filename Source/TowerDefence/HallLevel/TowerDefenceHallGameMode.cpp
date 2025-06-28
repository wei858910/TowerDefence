// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenceHallGameMode.h"

#include "TowerDefenceHallGameState.h"
#include "TowerDefenceHallHUD.h"
#include "TowerDefenceHallPawn.h"
#include "TowerDefenceHallPlayerController.h"

ATowerDefenceHallGameMode::ATowerDefenceHallGameMode()
{
    HUDClass = ATowerDefenceHallHUD::StaticClass();
    DefaultPawnClass = ATowerDefenceHallPawn::StaticClass();
    PlayerControllerClass = ATowerDefenceHallPlayerController::StaticClass();
    GameStateClass = ATowerDefenceHallGameState::StaticClass();
}
