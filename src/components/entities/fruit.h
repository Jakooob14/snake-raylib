#ifndef SNAKE_RAYLIB_FRUIT_H
#define SNAKE_RAYLIB_FRUIT_H
#include "entity.h"


class Fruit : public Entity
{
public:
    explicit Fruit(const Vector2& size) : size(size) {}

protected:
    void Update() override;
    void Draw() override;

private:
    Vector2 size{};
};


#endif //SNAKE_RAYLIB_FRUIT_H