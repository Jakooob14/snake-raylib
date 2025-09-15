#ifndef GAME_H
#define GAME_H
#include <memory>
#include <raylib.h>

#include "../systems/screens/screen.h"


class Ball;

class Game
{
public:
    void Run();

    void SetNextScreen(std::unique_ptr<Screen> screen);

    [[nodiscard]] bool IsGameOver() const { return gameOver; }
    void SetGameOver(const bool& value) { gameOver = value; }

    [[nodiscard]] int GetGameWidth() const { return gameWidth; }
    void SetGameWidth(const int& value) { gameWidth = value; }

    [[nodiscard]] int GetGameHeight() const { return gameHeight; }
    void SetGameHeight(const int& value) { gameHeight = value; }

    void Exit();

private:
    int gameWidth{640};
    int gameHeight{640};
    Color windowBackgroundColor{BLACK};
    RenderTexture2D renderTarget{};

    bool shouldExit{false};
    bool gameOver{false};

    std::unique_ptr<Screen> currentScreen{nullptr};
    std::unique_ptr<Screen> nextScreen{nullptr};


    void Update();
    void Draw();
    // Initialize starting game stuff
    void Initialize();
};


#endif //GAME_H
