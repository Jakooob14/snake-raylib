#ifndef INPUT_H
#define INPUT_H
#include "text.h"
#include "ui_component.h"


class Input : public Text
{
public:
    Input() : Text("16")
    {
        SetAdjustSize(false);
    }

    enum class InputTypes
    {
        INT = 0
    };

    template<typename T>
    [[nodiscard]] T GetValue();

protected:
    void Update() override;
    void Draw() override;

private:
    InputTypes inputType{InputTypes::INT};
};


#endif //INPUT_H
