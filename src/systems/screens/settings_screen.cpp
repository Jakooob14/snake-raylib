#include "settings_screen.h"

#include "menu_screen.h"
#include "../../components/ui/button.h"
#include "../../components/ui/input.h"
#include "../../components/ui/list_panel.h"
#include "../../core/game.h"

void SettingsScreen::Initialize()
{
    Screen::Initialize();

    ListPanel listPanel{};
    ListPanel gridRowsListPanel{ListPanel::ListDirection::ROW};
    listPanel.AddUIComponent(&gridRowsListPanel);

    auto* gridRowsText{AddComponent<Text>("Grid Rows:")};
    gridRowsText->SetAnchor(UIComponent::Anchor::CENTER);
    gridRowsText->SetFontSize(2.0f);
    gridRowsListPanel.AddUIComponent(gridRowsText);

    auto* input{AddComponent<Input>()};
    input->SetAnchor(UIComponent::Anchor::CENTER);
    input->SetFontSize(2.0f);
    gridRowsListPanel.AddUIComponent(input);

    auto* backButton{AddComponent<Button>()};
    backButton->SetText("Back");
    backButton->SetAnchor(UIComponent::Anchor::CENTER);
    backButton->SetFontSize(2.0f);
    backButton->SetOnClick([this](){ game.SetNextScreen(std::make_unique<MenuScreen>(game)); });
    listPanel.AddUIComponent(backButton);
}
