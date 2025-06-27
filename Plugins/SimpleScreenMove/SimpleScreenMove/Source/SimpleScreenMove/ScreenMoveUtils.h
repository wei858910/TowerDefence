#pragma once

enum class EScreenMoveState : uint8
{
    Screen_None,
    Screen_Left,
    Screen_Right,
    Screen_Up,
    Screen_Down,
    Screen_LeftUp,
    Screen_LeftDown,
    Screen_RightUp,
    Screen_RightDown,
    Screen_Max,
};

class SIMPLESCREENMOVE_API FScreenMoveUtils
{
public:
    static bool ListenScreenMove(const APlayerController* PlayerController, float ScreenMoveSpeed = 100.f);

private:
    static EScreenMoveState CursorMove(const APlayerController* PlayerController);

    static bool MoveDirection(const APlayerController* PlayerController, EScreenMoveState ScreenMoveState, const float ScreenMoveSpeed = 100.f);
};
