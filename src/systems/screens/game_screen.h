#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"
#include "../../utils/timers/function_timer.h"

class GameScreen : public Screen
{
public:
    explicit GameScreen(Game& game) : Screen(game) {}

protected:
    void Update() override;
    void Draw() override;
    void Initialize() override;

private:
};



#endif //GAME_SCREEN_H
