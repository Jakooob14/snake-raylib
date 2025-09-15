#include "settings_screen.h"

#include "menu_screen.h"
#include "../../components/ui/button.h"
#include "../../components/ui/input.h"
#include "../../core/game.h"

void SettingsScreen::Initialize()
{
    Screen::Initialize();

    // auto* width

    auto* backButton{AddComponent<Button>()};
    backButton->SetText("Back");
    backButton->SetAnchor(UIComponent::Anchor::CENTER);
    backButton->SetFontSize(2.0f);
    backButton->SetOnClick([this](){ game.SetNextScreen(std::make_unique<MenuScreen>(game)); });

    auto* input{AddComponent<Input>()};
    input->SetAnchor(UIComponent::Anchor::CENTER);
    input->SetFontSize(2.0f);
    input->SetPosition(Vector2{0.0f, 32.0f});
}
