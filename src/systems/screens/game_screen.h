#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"
#include "../../components/entities/player.h"
#include "../../components/ui/text.h"

class Fruit;

class GameScreen : public Screen
{
public:
    explicit GameScreen(Game& game) : Screen(game) {}

protected:
    void Update() override;
    void Draw() override;
    void Initialize() override;

private:
    const Vector2 playerSize{32.0f, 32.0f};
    int fruitCount{3};

    Text* gameOverText{nullptr};
    Player* player;

    std::vector<Fruit*> fruits{};

    void SpawnFruit();
};



#endif //GAME_SCREEN_H
