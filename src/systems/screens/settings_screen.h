#ifndef SETTINGS_SCREEN_H
#define SETTINGS_SCREEN_H
#include "screen.h"
#include "../../components/ui/list_panel.h"


class SettingsScreen : public Screen
{
public:
    explicit SettingsScreen(Game& game) : Screen(game) {}

protected:
    void Initialize() override;
};



#endif //SETTINGS_SCREEN_H
