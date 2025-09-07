#include "fruit.h"

void Fruit::Update()
{
}

void Fruit::Draw()
{
    const Vector2 pos{
        GetPosition().x * size.x,
        GetPosition().y * size.y
    };
    DrawRectangleV(pos, size, RED);
}
