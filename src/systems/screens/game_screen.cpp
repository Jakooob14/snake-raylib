#include "game_screen.h"

#include "../../components/entities/player.h"

void GameScreen::Update()
{
    Screen::Update();
}

void GameScreen::Draw()
{
    Screen::Draw();
}

void GameScreen::Initialize()
{
    Screen::Initialize();

    SetScreenBackgroundColor(Color{158, 196, 36});
    AddComponent<Player>();
}
