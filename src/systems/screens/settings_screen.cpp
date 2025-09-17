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

    gridRowsInput = CreateIntInput(128, "Grid Rows:", game.GetGridRows(), listPanel);
    maxFruitInput = CreateIntInput(128, "Max Fruit:", game.GetMaxFruit(), listPanel);

    auto* backButton{AddComponent<Button>()};
    backButton->SetText("Back");
    backButton->SetAnchor(UIComponent::Anchor::CENTER);
    backButton->SetFontSize(2.0f);
    backButton->SetOnClick([this](){ BackClick(); });
    listPanel.AddUIComponent(backButton);
}

void SettingsScreen::BackClick()
{
    const int gridRows{gridRowsInput->GetValue<int>()};
    if (gridRows >= 2 && gridRows <= 128) game.SetGridRows(gridRows);

    const int maxFruit{maxFruitInput->GetValue<int>()};
    if (maxFruit >= 1 && maxFruit <= 128) game.SetMaxFruit(maxFruit);

    game.SetNextScreen(std::make_unique<MenuScreen>(game));
}

Input* SettingsScreen::CreateIntInput(int max, const char* text, int defaultValue, ListPanel& listPanel)
{
    auto* panel = AddComponent<ListPanel>(ListPanel::ListDirection::ROW);
    listPanel.AddUIComponent(panel);

    auto* textUi{AddComponent<Text>(text)};
    textUi->SetAnchor(UIComponent::Anchor::CENTER);
    textUi->SetFontSize(2.0f);
    panel->AddUIComponent(textUi);

    auto* input = AddComponent<Input>();
    input->SetAnchor(UIComponent::Anchor::CENTER);
    input->SetFontSize(2.0f);
    input->SetMaxIntSize(max);
    input->SetText(std::to_string(defaultValue));
    panel->AddUIComponent(input);

    return input;
}
