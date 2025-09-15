#ifndef SCREEN_H
#define SCREEN_H
#include <memory>
#include <vector>
#include <raylib.h>

#include "../../components/game_component.h"

class Game;

class Screen
{
public:
    explicit Screen(Game& game) : game(game) {}
    virtual ~Screen() = default;

    [[nodiscard]] Color GetScreenBackgroundColor() const { return screenBackgroundColor; }
    void SetScreenBackgroundColor(const Color& value) { screenBackgroundColor = value; }

    /**
     * @brief Adds a new component of type T to the game.
     *
     * Creates and adds a component of type T to the `components` vector,
     * forwarding the provided arguments to T's constructor.
     *
     * @tparam T The type of the component to add. Must derive from GameComponent.
     * @tparam Args Argument types for T's constructor.
     * @param args Arguments to forward to T's constructor.
     * @return T* Pointer to the newly added component.
     */
    template<typename T, typename ...Args>
    T* AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of_v<GameComponent, T>, "T must inherit from GameComponent");

        // Create a smart pointer and forward `args` to it
        auto component = std::make_unique<T>(std::forward<Args>(args)...);

        T* ptr = component.get();

        components.push_back(std::move(component));

        return ptr;
    }

protected:
    virtual void Update();
    virtual void Draw();
    virtual void Initialize() {}

    Game& game;

    friend class Game;

private:
    Color screenBackgroundColor{BLACK};

    // All on-screen components
    std::vector<std::unique_ptr<GameComponent>> components{};
};



#endif //SCREEN_H
