#ifndef TEXT_H
#define TEXT_H
#include <utility>

#include "ui_component.h"
#include "../../core/globals.h"


class Text : public UIComponent
{
public:
    explicit Text(std::string text) : text(std::move(text)) {}

    [[nodiscard]] Color GetTextColor() const { return textColor; }
    void SetTextColor(const Color& value) { textColor = value; }

    [[nodiscard]] std::string GetText() const { return text; }
    void SetText(const std::string& value) { text = value; }

    [[nodiscard]] float GetFontSize() const { return fontSize; }
    void SetFontSize(const float& value) { fontSize = value; }

    [[nodiscard]] float GetSpacing() const { return spacing; }
    void SetSpacing(const float& value) { spacing = value; }

    [[nodiscard]] Font GetFont() const { return font; }
    void SetFont(const Font& value) { font = value; }

    [[nodiscard]] bool GetAdjustSize() const { return adjustSize; }
    void SetAdjustSize(const bool& value) { adjustSize = value; }

protected:
    void Draw() override;

private:
    Color textColor{WHITE};
    std::string text{};
    float fontSize{3.0f};
    float spacing{4.0f};
    Font font{mechaFont};
    bool adjustSize{true};
};



#endif //TEXT_H
