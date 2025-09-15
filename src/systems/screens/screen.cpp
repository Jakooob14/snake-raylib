#include "screen.h"

#include <algorithm>

#include "../../components/game_component.h"

#include <raylib.h>

void Screen::Update()
{
    for (auto &component : components) {
        if (!component) continue;
        if (component->IsDestroyed()) continue;

        if (!component->IsInitialized()) component->Initialize();
        component->Update();
    }

    // Remove components marked for destruction
    std::erase_if(components,
                  [](const std::unique_ptr<GameComponent>& component) { return component->IsDestroyed(); });
}

void Screen::Draw()
{
    ClearBackground(screenBackgroundColor);

    for (auto& component : components) {
        if (!component) continue;
        component->Draw();
    }
}
