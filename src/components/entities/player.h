#ifndef SNAKE_RAYLIB_PLAYER_H
#define SNAKE_RAYLIB_PLAYER_H
#include "entity.h"
#include "../game_component.h"


class Player : public Entity
{
protected:
    void Update() override;
    void Draw() override;

private:
    Vector2 size{20.0, 20.0};
    float speed{20.0f};
    Vector2 velocity{speed, 0.0f};

    float baseTimeToMove{0.25f};
    float timeToMove{baseTimeToMove};

    void Move();
    // Changes the `velocity` variable based on the pressed button
    void Direction();
};


#endif //SNAKE_RAYLIB_PLAYER_H