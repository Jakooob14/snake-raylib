#include "button.h"

#include "raylib.h"
#include "../../core/globals.h"

void Button::Draw()
{
    UIComponent::Draw();
    
    if (!IsDrawn()) return;

    const Vector2 position{GetPosition()};
    const Vector2 size{GetSize()};

    DrawRectangleV(position, size, IsHovering() ? backgroundColor : textColor);

    const float fontSizeFinal{static_cast<float>(mechaFont.baseSize) * fontSize};
    constexpr float spacing{4.0f};

    const Vector2 textPos{
        size.x / 2.0f - MeasureTextEx(mechaFont, text, fontSizeFinal, spacing).x / 2.0f + position.x,
        size.y / 2.0f - MeasureTextEx(mechaFont, text, fontSizeFinal, spacing).y / 2.0f + position.y
    };

    DrawTextEx(mechaFont, text, textPos, fontSizeFinal, spacing, IsHovering() ? textColor : backgroundColor);
}