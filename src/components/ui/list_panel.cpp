#include "list_panel.h"

#include <cstdio>

void ListPanel::AddUIComponent(UIComponent* uiComponent)
{
    uiComponents.push_back(uiComponent);

    for (int i = 0; i < uiComponents.size(); ++i)
    {
        const Vector2 pos{uiComponents[i]->GetBasePosition()};
        const Vector2 thisPos{GetPosition()};

        switch (listDirection)
        {
            case ListDirection::COLUMN:
                uiComponents[i]->SetPosition(Vector2{pos.x, i * (i > 0 ? uiComponents[i - 1]->GetSize().y : 0)});
                break;
            case ListDirection::ROW:
                uiComponents[i]->SetPosition(Vector2{i * (i > 0 ? uiComponents[i - 1]->GetSize().x : 0), pos.y});
                if (GetAnchor() == Anchor::CENTER)
                {
                    printf("%f, %f\n", pos.y, thisPos.y);
                }
                break;
        }

    }
}
