// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenceGameMode.h"

#include "TowerDefenceGameCamera.h"
#include "TowerDefenceMainLevelHUD.h"
#include "TowerDefenceGameState.h"
#include "TowerDefencePlayerController.h"
#include "TowerDefencePlayerState.h"

ATowerDefenceGameMode::ATowerDefenceGameMode()
{
	DefaultPawnClass = ATowerDefenceGameCamera::StaticClass();
	HUDClass = ATowerDefenceMainLevelHUD::StaticClass();
	PlayerControllerClass = ATowerDefencePlayerController::StaticClass();
	GameStateClass = ATowerDefenceGameState::StaticClass();
	PlayerStateClass = ATowerDefencePlayerState::StaticClass();	
}
