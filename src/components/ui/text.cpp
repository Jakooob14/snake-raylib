#include "text.h"

#include "../../core/globals.h"
#include "../../systems/screens/screen.h"

void Text::Draw()
{
    UIComponent::Draw();

    if (!IsDrawn()) return;

    const float actualFontSize{static_cast<float>(font.baseSize) * fontSize};
    SetSize(MeasureTextEx(font, text.c_str(), actualFontSize, spacing));
    DrawTextEx(font, text.c_str(), GetPosition(), actualFontSize, spacing, textColor);
}