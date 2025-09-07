#ifndef SNAKE_RAYLIB_ENTITY_H
#define SNAKE_RAYLIB_ENTITY_H
#include "raylib.h"
#include "../game_component.h"


class Entity : public GameComponent
{
public:
    [[nodiscard]] Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2& value) { position = value; }

private:
    Vector2 position{0.0, 0.0};
};


#endif //SNAKE_RAYLIB_ENTITY_H