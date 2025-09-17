#include "text.h"

#include "../../core/globals.h"
#include "../../systems/screens/screen.h"

void Text::SetFontSize(const float& value)
{
    fontSize = value;

    if (!adjustSize) return;
    const float actualFontSize{static_cast<float>(font.baseSize) * fontSize};
    SetSize(MeasureTextEx(font, text.c_str(), actualFontSize, spacing));
}

void Text::Draw()
{
    UIComponent::Draw();

    if (!IsDrawn()) return;

    const float actualFontSize{static_cast<float>(font.baseSize) * fontSize};

    DrawTextEx(font, text.c_str(), GetPosition(), actualFontSize, spacing, textColor);
}
