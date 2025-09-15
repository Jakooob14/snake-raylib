#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H
#include <functional>

#include "raylib.h"
#include "../game_component.h"


// TODO: Redo whole UI system so it works correctly using relative and child values

class UIComponent : public GameComponent
{
public:
    UIComponent() = default;

    enum class Anchor {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT,
        CENTER_LEFT,
        CENTER_RIGHT,
        CENTER
    };

    [[nodiscard]] Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2& value);

    [[nodiscard]] Vector2 GetSize() const { return size; }
    void SetSize(const Vector2& value);

    void SetOnClick(const std::function<void()>& value) { onClick = value; }

    [[nodiscard]] bool IsHovering() const;

    [[nodiscard]] Anchor GetAnchor() const { return anchor; }
    void SetAnchor(const Anchor& value);

    [[nodiscard]] Vector2 GetBasePosition() const { return basePosition; }

    [[nodiscard]] bool IsDrawn() const { return isDrawn; }
    void SetIsDrawn(const bool& value) { isDrawn = value; }

protected:
    void Update() override;
    void Draw() override {};
    virtual Vector2 CalculateAnchoredPosition();

private:
    Vector2 position{0.0f, 0.0f};
    Vector2 size{150.0f, 30.0f};
    Color backgroundColor{WHITE};
    Color textColor{BLACK};
    const char* text{};
    Anchor anchor{Anchor::TOP_LEFT};
    bool isDrawn{true};

    Vector2 basePosition{};

    bool hasClicked{false};

    std::function<void()> onClick{nullptr};
};



#endif //UI_COMPONENT_H
