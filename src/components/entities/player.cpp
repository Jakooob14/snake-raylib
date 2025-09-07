#include "player.h"

#include <cstdio>

#include "raylib.h"
#include "../../utils/input.h"

void Player::Update()
{
    Move();
    Direction();
}

void Player::Draw()
{
    DrawRectangleV(GetPosition(), size, BLACK);
}

void Player::Move()
{
    const float deltaTime{GetFrameTime()};

    timeToMove -= deltaTime;

    if (timeToMove <= 0.0f)
    {
        Vector2 pos{GetPosition()};

        pos = Vector2{
            pos.x + velocity.x,
            pos.y + velocity.y
        };

        if (pos.x >= GetScreenWidth())
        {
            pos = Vector2{
                0.0f,
                pos.y
            };
        }

        if (pos.x < 0.0f)
        {
            pos = Vector2{
                static_cast<float>(GetScreenWidth()) - size.x,
                pos.y
            };
        }

        if (pos.y >= GetScreenHeight())
        {
            pos = Vector2{
                pos.x,
                0.0f
            };
        }

        if (pos.y < 0.0f)
        {
            pos = Vector2{
                pos.x,
                static_cast<float>(GetScreenHeight()) - size.y
            };
        }

        SetPosition(pos);

        timeToMove = baseTimeToMove;
    }
}

void Player::Direction()
{
    if (input::IsMoveUp())
    {
        velocity = Vector2{0.0f, -speed};
        return;
    }

    if (input::IsMoveDown())
    {
        velocity = Vector2{0.0f, speed};
        return;
    }

    if (input::IsMoveRight())
    {
        velocity = Vector2{speed, 0.0f};
        return;
    }

    if (input::IsMoveLeft())
    {
        velocity = Vector2{-speed, 0.0f};
        return;
    }
}
