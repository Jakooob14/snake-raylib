#include "input.h"

void Input::Update()
{
    Text::Update();

    if (IsHovering())
    {
        SetTextColor(RED);

        const int key{GetCharPressed()};
        if (key >= 32 && key <= 125)
        {
            std::string newText = GetText();
            newText += static_cast<char>(key);
            SetText(newText);
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            std::string newText = GetText();
            if (!newText.empty())
            {
                newText.pop_back();
                SetText(newText);
            }
        }
    } else
    {
        SetTextColor(WHITE);
    }
}

void Input::Draw()
{
    Text::Draw();

    DrawRectangleV(Vector2{GetPosition().x, GetPosition().y + GetSize().y - 3.0f}, Vector2{GetSize().x, 3.0f}, GetTextColor());
}
