#ifndef SNAKE_RAYLIB_PLAYER_H
#define SNAKE_RAYLIB_PLAYER_H
#include <vector>

#include "entity.h"
#include "fruit.h"
#include "../game_component.h"


class Game;

class Player : public Entity
{
public:
    explicit Player(const Vector2& size, std::vector<Fruit*>& fruits, Game& game) :
    size(size), fruits(fruits), game(game) {}

    [[nodiscard]] std::vector<Vector2> GetSegments() const { return segments; }

protected:
    void Update() override;
    void Draw() override;

private:
    Vector2 size{20.0, 20.0};
    Vector2 direction{1.0f, 0.0f};

    float baseTimeToMove{0.25f};
    float timeToMove{baseTimeToMove};

    std::vector<Vector2> segments{Vector2{0.0f, 0.0f}};

    std::vector<Fruit*>& fruits;
    Game& game;

    void Move();
    // Changes the `velocity` variable based on the pressed button
    void Direction();
};


#endif //SNAKE_RAYLIB_PLAYER_H