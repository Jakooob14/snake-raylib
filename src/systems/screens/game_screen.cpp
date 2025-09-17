#include "game_screen.h"

#include "../../components/entities/fruit.h"
#include "../../components/entities/player.h"
#include "../../components/ui/text.h"
#include "../../core/game.h"
#include "../../utils/random.h"

void GameScreen::Update()
{
    Screen::Update();

    // Prevent fruit overflow
    const int maxFruit{static_cast<int>(pow(game.GetGridRows(), 2) - player->GetSegments().size())};
    if (fruitCount >= maxFruit)
    {
        fruitCount = maxFruit;
    }

    if (fruits.size() < fruitCount)
    {
        for (size_t i = 0; fruitCount - fruits.size() > 0; ++i)
        {
            SpawnFruit();
        }
    }

    if (game.IsGameOver() && gameOverText == nullptr)
    {
        gameOverText = AddComponent<Text>("Game Over!");
        gameOverText->SetAnchor(UIComponent::Anchor::CENTER);
        gameOverText->SetFontSize(8.0f);
    }
}

void GameScreen::Draw()
{
    Screen::Draw();
}

void GameScreen::Initialize()
{
    Screen::Initialize();

    game.SetGameOver(false);

    SetScreenBackgroundColor(Color{158, 196, 36, 255});
    player = AddComponent<Player>(playerSize, fruits, game);
}

void GameScreen::SpawnFruit()
{
    const Vector2 pos{
            static_cast<float>(GetRandomInt(0, gameWidth / playerSize.x - 1)),
            static_cast<float>(GetRandomInt(0, gameHeight / playerSize.y - 1))
    };

    // Check if new fruit would spawn at player, if yes try again
    for (auto segment: player->GetSegments())
    {
        if (pos.x != segment.x || pos.y != segment.y) continue;

        printf("trying again\n");
        SpawnFruit();
        return;
    }

    // Check if new fruit would spawn at another fruit, if yes try again
    for (auto fruit: fruits)
    {
        if (pos.x != fruit->GetPosition().x || pos.y != fruit->GetPosition().y) continue;

        printf("trying again\n");
        SpawnFruit();
        return;
    }
    printf("spawned at %f, %f\n", pos.x, pos.y);

    Fruit* fruit{AddComponent<Fruit>(playerSize)};
    fruit->SetPosition(pos);
    fruits.push_back(fruit);
}
