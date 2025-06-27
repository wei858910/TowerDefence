// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "MonsterAIController.generated.h"

UCLASS()
class TOWERDEFENCE_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMonsterAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
