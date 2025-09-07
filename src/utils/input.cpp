#include "input.h"
#include <raylib.h>

namespace input
{
    bool IsMoveUp()
    {
        return IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
    }

    bool IsMoveDown()
    {
        return IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
    }

    bool IsMoveLeft()
    {
        return IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
    }

    bool IsMoveRight()
    {
        return IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);
    }

    bool IsConfirming()
    {
        return IsMouseButtonDown(0);
    }
}
