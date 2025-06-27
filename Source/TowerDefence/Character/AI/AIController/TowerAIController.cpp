// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerAIController.h"


// Sets default values
ATowerAIController::ATowerAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATowerAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

