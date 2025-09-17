#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"
#include "../../components/entities/player.h"
#include "../../components/ui/text.h"
#include "../../core/game.h"

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
    const Vector2 playerSize{
        static_cast<float>(gameWidth / game.GetGridRows()),
        static_cast<float>(gameHeight / game.GetGridRows())
    };
    int fruitCount{game.GetMaxFruit()};

    Text* gameOverText{nullptr};
    Player* player;

    std::vector<Fruit*> fruits{};

    void SpawnFruit();
};



#endif //GAME_SCREEN_H
