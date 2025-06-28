// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenceGameCamera.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TowerDefence/Utils/SimpleLog.h"


// Sets default values
ATowerDefenceGameCamera::ATowerDefenceGameCamera()
{
    PrimaryActorTick.bCanEverTick = false;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    CameraBoom->TargetArmLength = CameraZoomMaxArmLength;
    CameraBoom->SetRelativeRotation(FRotator(-60.0, 0.0, 0.0));

    MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
    MainCamera->AttachToComponent(CameraBoom, FAttachmentTransformRules::KeepRelativeTransform);

    MarkBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MarkBox"));
    MarkBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATowerDefenceGameCamera::BeginPlay()
{
    Super::BeginPlay();
}

void ATowerDefenceGameCamera::Zoom(bool bDirection)
{
    if (bDirection)
    {
        if (CameraBoom->TargetArmLength > CameraZoomMinArmLength)
        {
            CameraBoom->TargetArmLength -= CameraZoomSpeed;
        }
    }
    else
    {
        if (CameraBoom->TargetArmLength < CameraZoomMaxArmLength)
        {
            CameraBoom->TargetArmLength += CameraZoomSpeed;
        }
    }

    LOG_WARN("TargetArmLength = %f", CameraBoom->TargetArmLength);
    SCREEN_WARN("TargetArmLength = %f", CameraBoom->TargetArmLength);
}
