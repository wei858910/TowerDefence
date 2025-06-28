// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TowerDefenceGameCamera.generated.h"

class UBoxComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOWERDEFENCE_API ATowerDefenceGameCamera : public APawn
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    UCameraComponent* MainCamera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(AllowPrivateAccess="true"))
    UBoxComponent* MarkBox;

    float CameraZoomMaxArmLength{4000.f};
    float CameraZoomMinArmLength{400.f};
    float CameraZoomSpeed{150.f};

public:
    ATowerDefenceGameCamera();

    void Zoom(bool bDirection);

protected:
    virtual void BeginPlay() override;
};
