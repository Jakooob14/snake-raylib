#include "list_panel.h"

#include <cstdio>

void ListPanel::AddUIComponent(UIComponent* uiComponent)
{
    uiComponents.push_back(uiComponent);

    float yOffset = 0.0f;
    float xOffset = 0.0f;
    Vector2 panelPos = GetPosition();

    for (int i = 0; i < uiComponents.size(); ++i)
    {
        switch (listDirection)
        {
            case ListDirection::COLUMN:
                if (i > 0) yOffset += uiComponents[i - 1]->GetSize().y;
                uiComponents[i]->SetPosition(Vector2{panelPos.x, panelPos.y + yOffset});
                break;
            case ListDirection::ROW:
                if (i > 0) xOffset += uiComponents[i - 1]->GetSize().x + 32.0f;
                uiComponents[i]->SetPosition(Vector2{panelPos.x + xOffset, panelPos.y});
                break;
        }
    }
}