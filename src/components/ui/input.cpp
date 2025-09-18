#include <string>

#include "input.h"

void Input::Update()
{
    Text::Update();

    if (IsHovering())
    {
        SetTextColor(RED);

        const int key{GetCharPressed()};

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            std::string newText = GetText();
            if (!newText.empty())
            {
                newText.pop_back();
                SetText(newText);
            }
        }

        std::string newText = GetText();
        newText += static_cast<char>(key);

        switch (inputType)
        {
            case InputTypes::INT:
                if (key < 48 || key > 57 || std::stoi(newText) > maxIntSize) return;

        }

        SetText(newText);
    } else
    {
        SetTextColor(WHITE);
    }
}

void Input::Draw()
{
    Text::Draw();

    if (!IsDrawn()) return;

    DrawRectangleV(Vector2{GetPosition().x, GetPosition().y + GetSize().y}, Vector2{GetSize().x, 3.0f}, GetTextColor());
}

