#include "input.h"

template<typename T>
T Input::GetValue()
{
    switch (inputType)
    {
        case InputTypes::INT:
            if (GetText().empty()) return 0;
            if (std::is_same_v<T, int>) return std::stoi(GetText());
        default:
            throw;
    }
}

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

        int pressedKey{};

        switch (inputType)
        {
            case InputTypes::INT:
                if (key >= 48 && key <= 57 && GetValue<int>() <= 999999999) pressedKey = key;

        }

        if (!pressedKey) return;

        std::string newText = GetText();
        newText += static_cast<char>(pressedKey);
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

