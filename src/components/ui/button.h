#ifndef BUTTON_H
#define BUTTON_H
#include <functional>

#include "raylib.h"
#include "ui_component.h"


class Button : public UIComponent
{
public:
    [[nodiscard]] Color GetBackgroundColor() const { return backgroundColor; }
    void SetBackgroundColor(const Color value) { backgroundColor = value; }
    [[nodiscard]] const char *GetText() const { return text; }
    void SetText(const char* value) { text = value; }
    [[nodiscard]] float GetFontSize() const { return fontSize; }
    void SetFontSize(const float& value) { fontSize = value; }

protected:
    void Draw() override;

private:
    Color backgroundColor{WHITE};
    Color textColor{BLACK};
    const char* text{};
    float fontSize{3.0f};
};



#endif //BUTTON_H
