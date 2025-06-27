#include "ScreenMoveUtils.h"

bool FScreenMoveUtils::ListenScreenMove(const APlayerController* PlayerController, const float ScreenMoveSpeed)
{
    return MoveDirection(PlayerController, CursorMove(PlayerController), ScreenMoveSpeed);
}

EScreenMoveState FScreenMoveUtils::CursorMove(const APlayerController* PlayerController)
{
    // 屏幕尺寸
    int32 SizeX = INDEX_NONE;
    int32 SizeY = INDEX_NONE;

    // 鼠标位置
    float MouseX = -MAX_flt;
    float MouseY = -MAX_flt;

    if (PlayerController)
    {
        PlayerController->GetViewportSize(SizeX, SizeY);
        PlayerController->GetMousePosition(MouseX, MouseY);
        if (MouseX >= 0.f && MouseX <= SizeX && MouseY >= 0.f && MouseY <= SizeY)
        {
            if (constexpr float MousePositionRange = 10.f; FMath::IsNearlyEqual(MouseX, 0.f, MousePositionRange) && FMath::IsNearlyEqual(MouseY, 0.f, MousePositionRange))
            {
                return EScreenMoveState::Screen_LeftUp;
            }
            else if (FMath::IsNearlyEqual(SizeX, MouseX, MousePositionRange) && FMath::IsNearlyEqual(MouseY, 0.f, MousePositionRange))
            {
                return EScreenMoveState::Screen_RightUp;
            }
            else if (FMath::IsNearlyEqual(MouseX, 0.f, MousePositionRange) && FMath::IsNearlyEqual(SizeY, MouseY, MousePositionRange))
            {
                return EScreenMoveState::Screen_LeftDown;
            }
            else if (FMath::IsNearlyEqual(SizeX, MouseX, MousePositionRange) && FMath::IsNearlyEqual(SizeY, MouseY, MousePositionRange))
            {
                return EScreenMoveState::Screen_RightDown;
            }
            else if (FMath::IsNearlyEqual(MouseX, 0.f, MousePositionRange))
            {
                return EScreenMoveState::Screen_Left;
            }
            else if (FMath::IsNearlyEqual(SizeX, MouseX, MousePositionRange))
            {
                return EScreenMoveState::Screen_Right;
            }
            else if (FMath::IsNearlyEqual(MouseY, 0.f, MousePositionRange))
            {
                return EScreenMoveState::Screen_Up;
            }
            else if (FMath::IsNearlyEqual(SizeY, MouseY, MousePositionRange))
            {
                return EScreenMoveState::Screen_Down;
            }
        }
    }

    return EScreenMoveState::Screen_None;
}

bool FScreenMoveUtils::MoveDirection(const APlayerController* PlayerController, const EScreenMoveState ScreenMoveState, const float ScreenMoveSpeed)
{
    FVector OffsetValue = FVector::ZeroVector;
    if (PlayerController && PlayerController->GetPawn())
    {
        switch (ScreenMoveState)
        {
        case EScreenMoveState::Screen_LeftUp:
            OffsetValue = FVector(ScreenMoveSpeed, -ScreenMoveSpeed, 0.f);
            break;
        case EScreenMoveState::Screen_RightUp:
            OffsetValue = FVector(ScreenMoveSpeed, ScreenMoveSpeed, 0.f);
            break;
        case EScreenMoveState::Screen_LeftDown:
            OffsetValue = FVector(-ScreenMoveSpeed, -ScreenMoveSpeed, 0.f);
            break;
        case EScreenMoveState::Screen_RightDown:
            OffsetValue = FVector(-ScreenMoveSpeed, ScreenMoveSpeed, 0.f);
            break;
        case EScreenMoveState::Screen_Left:
            OffsetValue = FVector(0.f, -ScreenMoveSpeed, 0.f);
            break;
        case EScreenMoveState::Screen_Right:
            OffsetValue = FVector(0.f, ScreenMoveSpeed, 0.f);
            break;
        case EScreenMoveState::Screen_Up:
            OffsetValue = FVector(ScreenMoveSpeed, 0.f, 0.f);
            break;
        case EScreenMoveState::Screen_Down:
            OffsetValue = FVector(-ScreenMoveSpeed, 0.f, 0.f);
            break;
        default: ;
        }
        PlayerController->GetPawn()->AddActorWorldOffset(OffsetValue);
    }
    return OffsetValue != FVector::ZeroVector;
}
