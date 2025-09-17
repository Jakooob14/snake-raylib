#ifndef GAME_H
#define GAME_H
#include <memory>
#include <raylib.h>

#include "globals.h"
#include "../systems/screens/screen.h"


class Ball;

class Game
{
public:
    void Run();

    void SetNextScreen(std::unique_ptr<Screen> screen);

    [[nodiscard]] bool IsGameOver() const { return gameOver; }
    void SetGameOver(const bool& value) { gameOver = value; }

    [[nodiscard]] int GetGridRows() const { return gridRows; }
    void SetGridRows(const int& value) { gridRows = value; }

    [[nodiscard]] int GetMaxFruit() const { return maxFruit; }
    void SetMaxFruit(const int& value) { maxFruit = value; }

    void Exit();

private:
    Color windowBackgroundColor{BLACK};
    RenderTexture2D renderTarget{};

    int gridRows{16};
    int maxFruit{3};

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
