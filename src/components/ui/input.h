#ifndef INPUT_H
#define INPUT_H
#include "text.h"
#include "ui_component.h"


class Input : public Text
{
public:
    Input() : Text("16") {}

protected:
    void Update() override;
    void Draw() override;
};



#endif //INPUT_H
