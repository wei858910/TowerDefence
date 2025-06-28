// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefencePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TowerDefenceGameCamera.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "SimpleScreenMove/ScreenMoveUtils.h"

ATowerDefencePlayerController::ATowerDefencePlayerController()
{
    bShowMouseCursor = true;
    ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_TowerDefenceRef(TEXT("/Game/Input/IMC_TowerDefence.IMC_TowerDefence"));
    IMC_TowerDefence = IMC_TowerDefenceRef.Object;
    check(IMC_TowerDefence);

    ConstructorHelpers::FObjectFinder<UInputAction> IA_MouseWheelRef(TEXT("/Game/Input/IA_MouseWheel.IA_MouseWheel"));
    IA_MouseWheel = IA_MouseWheelRef.Object;
    check(IA_MouseWheel);
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

void ATowerDefencePlayerController::MouseWheelAxis(FInputActionValue& ActionValue)
{
    if (ATowerDefenceGameCamera* ControlledPawn = Cast<ATowerDefenceGameCamera>(GetPawn()))
    {
        if (const float AxisValue = ActionValue.Get<float>(); AxisValue > 0)
        {
            ControlledPawn->Zoom(true);
        }
        else if (AxisValue < 0)
        {
            ControlledPawn->Zoom(false);
        }
    }
}

void ATowerDefencePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
        {
            if (IMC_TowerDefence && IA_MouseWheel)
            {
                EnhancedInputSubsystem->AddMappingContext(IMC_TowerDefence, 0, FModifyContextOptions{});
                EnhancedInputComponent->BindAction(IA_MouseWheel, ETriggerEvent::Triggered, this, FEnhancedInputActionHandlerValueSignature::TMethodPtr<ThisClass>(&ThisClass::MouseWheelAxis));
            }
        };
    }
}

void ATowerDefencePlayerController::LimitMousePosition()
{
    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
    InputMode.SetHideCursorDuringCapture(false);
    SetInputMode(InputMode);
}
