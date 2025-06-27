// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIController.h"


// Sets default values
AMonsterAIController::AMonsterAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMonsterAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

