#include "player.h"

#include <cstdio>
#include <algorithm>

#include "raylib.h"
#include "../../core/game.h"
#include "../../utils/input.h"

void Player::Update()
{
    Move();
    Direction();
}

void Player::Draw()
{
    for (auto segment: segments)
    {
        const Vector2 pos{
            segment.x * size.x,
            segment.y * size.y
        };

        DrawRectangleV(pos, size, BLACK);
    }
}

void Player::Move()
{
    if (game.IsGameOver()) return;

    const float deltaTime{GetFrameTime()};

    timeToMove -= deltaTime;

    if (timeToMove <= 0.0f)
    {
        timeToMove = baseTimeToMove;

        const Vector2 firstSegment{segments.back()};
        Vector2 pos{
            firstSegment.x + direction.x,
            firstSegment.y + direction.y
        };

        // Wall collisions
        if (pos.x * size.x >= GetScreenWidth()) pos.x = 0.0f;
        if (pos.x < 0.0f) pos.x = GetScreenWidth() / size.x - 1.0f;
        if (pos.y * size.y >= GetScreenHeight()) pos.y = 0.0f;
        if (pos.y < 0.0f) pos.y = GetScreenHeight() / size.y - 1.0f;

        // Create a new segment at the direciton of the snake
        segments.push_back(pos);

        bool ateFruit{false};

        // If the snake is not touching a fruit remove the last segment
        for (auto it = fruits.begin(); it != fruits.end();)
        {
            const Vector2 fruitPos{(*it)->GetPosition()};
            if (fruitPos.x == pos.x && fruitPos.y == pos.y)
            {
                printf("hit\n");
                (*it)->Destroy();
                it = fruits.erase(it);
                ateFruit = true;
                break;
            } else
            {
                ++it;
            }
        }

        if (!ateFruit) segments.erase(segments.begin());

        // Self collision
        for (size_t i = 0; i < segments.size() - 1; ++i)
        {
            if (segments[i].x == segments.back().x && segments[i].y == segments.back().y)
            {
                game.SetGameOver(true);
                return;
            }
        }
    }
}

void Player::Direction()
{
    if (input::IsMoveUp() && direction.y != 1.0f)
    {
        direction = Vector2{0.0f, -1.0f};
        return;
    }

    if (input::IsMoveDown() && direction.y != -1.0f)
    {
        direction = Vector2{0.0f, 1.0f};
        return;
    }

    if (input::IsMoveRight() && direction.x != -1.0f)
    {
        direction = Vector2{1.0f, 0.0f};
        return;
    }

    if (input::IsMoveLeft() && direction.x != 1.0f)
    {
        direction = Vector2{-1.0f, 0.0f};
        return;
    }
}
