#include "ui_component.h"

#include "raylib.h"
#include "../../core/globals.h"
#include "../../utils/input.h"

void UIComponent::Update()
{
    // Make sure it sends event only once with `clicked` bool
    if (input::IsConfirming() && IsHovering() && !hasClicked)
    {
        hasClicked = true;
    }

    // Reset click
    if (hasClicked && !input::IsConfirming())
    {
        if (onClick) onClick();
        hasClicked = false;
    }
}

Vector2 UIComponent::CalculateAnchoredPosition()
{
    const Vector2 windowSize{
        static_cast<float>(gameWidth),
        static_cast<float>(gameHeight)
    };

    Vector2 anchoredPosition{};

    switch (anchor) {
        case Anchor::TOP_RIGHT:
            anchoredPosition.x = windowSize.x - size.x + basePosition.x;
            anchoredPosition.y = basePosition.y;
            break;
        case Anchor::TOP_CENTER:
            anchoredPosition.x = windowSize.x / 2.0f - size.x / 2.0f + basePosition.x;
            anchoredPosition.y = basePosition.y;
            break;
        case Anchor::BOTTOM_LEFT:
            anchoredPosition.x = basePosition.x;
            anchoredPosition.y = windowSize.y - size.y + basePosition.y;
            break;
        case Anchor::BOTTOM_CENTER:
            anchoredPosition.x = windowSize.x / 2.0f - size.x / 2.0f + basePosition.x;
            anchoredPosition.y = windowSize.y - size.y + basePosition.y;
            break;
        case Anchor::BOTTOM_RIGHT:
            anchoredPosition.x = windowSize.x - size.x + basePosition.x;
            anchoredPosition.y = windowSize.y - size.y + basePosition.y;
            break;
        case Anchor::CENTER_LEFT:
            anchoredPosition.x = basePosition.x;
            anchoredPosition.y = windowSize.y / 2.0f - size.y / 2.0f + basePosition.y;
            break;
        case Anchor::CENTER_RIGHT:
            anchoredPosition.x = windowSize.x - size.x + basePosition.x;
            anchoredPosition.y = windowSize.y / 2.0f - size.y / 2.0f + basePosition.y;
            break;
        case Anchor::CENTER:
            anchoredPosition.x = windowSize.x / 2.0f - size.x / 2.0f + basePosition.x;
            anchoredPosition.y = windowSize.y / 2.0f - size.y / 2.0f + basePosition.y;
            break;
        default:
            return basePosition;
    }

    return anchoredPosition;
}

void UIComponent::SetPosition(const Vector2& value)
{
    basePosition = value;
    position = CalculateAnchoredPosition();
}

void UIComponent::SetSize(const Vector2& value)
{
    size = value;
    position = CalculateAnchoredPosition();
}

bool UIComponent::IsHovering() const
{
    Vector2 mousePos = GetMousePosition();

    // Calculate scale and offset (should match your Draw() logic)
    float scaleX = static_cast<float>(GetScreenWidth()) / gameWidth;
    float scaleY = static_cast<float>(GetScreenHeight()) / gameHeight;
    float scale = std::min(scaleX, scaleY);

    float destWidth = gameWidth * scale;
    float destHeight = gameHeight * scale;
    float offsetX = (static_cast<float>(GetScreenWidth()) - destWidth) * 0.5f;
    float offsetY = (static_cast<float>(GetScreenHeight()) - destHeight) * 0.5f;

    // Transform mouse position to render target space
    mousePos.x = (mousePos.x - offsetX) / scale;
    mousePos.y = (mousePos.y - offsetY) / scale;

    if (mousePos.x < position.x) return false;
    if (mousePos.x > size.x + position.x) return false;
    if (mousePos.y < position.y) return false;
    if (mousePos.y > size.y + position.y) return false;

    return true;
}

void UIComponent::SetAnchor(const Anchor& value)
{
    anchor = value;
    position = CalculateAnchoredPosition();
}
