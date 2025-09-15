#ifndef SNAKE_RAYLIB_LIST_PANEL_H
#define SNAKE_RAYLIB_LIST_PANEL_H
#include "ui_component.h"


class ListPanel : public UIComponent
{
public:
    enum class ListDirection
    {
        COLUMN,
        ROW
    };

    ListPanel() = default;
    explicit ListPanel(const ListDirection& listDirection) : listDirection(listDirection) {}


    [[nodiscard]] ListDirection GetListDirection() const { return listDirection; }
    void SetListDirection(const ListDirection& value) { listDirection = value; }

    void AddUIComponent(UIComponent* uiComponent);

private:
    std::vector<UIComponent*> uiComponents{};

    ListDirection listDirection{ListDirection::COLUMN};
};


#endif //SNAKE_RAYLIB_LIST_PANEL_H