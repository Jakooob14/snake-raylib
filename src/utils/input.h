#ifndef INPUT_H
#define INPUT_H


enum class PlayerId;

namespace input
{
    bool IsMoveUp();
    bool IsMoveDown();
    bool IsMoveLeft();
    bool IsMoveRight();

    bool IsConfirming();
}



#endif //INPUT_H
