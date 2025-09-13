#include "game.h"

#include <cassert>
#include <raylib.h>

#include "globals.h"
#include "../systems/screens/game_screen.h"
#include "../systems/screens/menu_screen.h"
#include "../systems/screens/screen.h"
#include "../systems/screens/settings_screen.h"

void Game::Run()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(gameWidth, gameHeight, "Snake");
    SetTargetFPS(60);

    Initialize();

    while (!WindowShouldClose() && !shouldExit)
    {
        Update();
        Draw();
    }

    CloseWindow();
}

void Game::SetCurrentScreen(std::unique_ptr<Screen> screen)
{
    currentScreen = std::move(screen);
    currentScreen->Initialize();
}

void Game::Exit() {
    shouldExit = true;
}

void Game::Update()
{
    const float deltaTime{GetFrameTime()};

    timerManager.UpdateTimers(deltaTime);

    assert(currentScreen && "currentScreen is null in Game::Update()");
    currentScreen->Update();
}

void Game::Draw()
{
    BeginTextureMode(renderTarget);
    ClearBackground(windowBackgroundColor);
    if (currentScreen) currentScreen->Draw();
    EndTextureMode();

    // Draw the render texture scaled to the window maintaining aspect ratio
    BeginDrawing();
    ClearBackground(windowBackgroundColor);

    const float scaleX = static_cast<float>(GetScreenWidth()) / gameWidth;
    const float scaleY = static_cast<float>(GetScreenHeight()) / gameHeight;
    const float scale = std::min(scaleX, scaleY);

    const float destWidth = gameWidth * scale;
    const float destHeight = gameHeight * scale;
    const float offsetX = (static_cast<float>(GetScreenWidth()) - destWidth) * 0.5f;
    const float offsetY = (static_cast<float>(GetScreenHeight()) - destHeight) * 0.5f;

    // Flip vertically
    const Rectangle src = { 0, 0, static_cast<float>(gameWidth), -static_cast<float>(gameHeight) };

    const Rectangle dest = { offsetX, offsetY, destWidth, destHeight };

    DrawTexturePro(renderTarget.texture, src, dest, {0, 0}, 0.0f, WHITE);

    EndDrawing();
}

void Game::Initialize()
{
    // Load the render texture for the window
    renderTarget = LoadRenderTexture(gameWidth, gameHeight);

    // Load global assets
    mechaFont = LoadFont("./resources/fonts/mecha.png");

    // Create and set current screen
    SetCurrentScreen(std::make_unique<MenuScreen>(*this));
}
