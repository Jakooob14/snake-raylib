#ifndef INPUT_H
#define INPUT_H

#include <string>

#include "text.h"


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
    T GetValue()
    {
        switch (inputType)
        {
            case InputTypes::INT:
                if (GetText().empty()) return 0;
                if (std::is_same_v<T, int>) return std::stoi(GetText());
            default:
                throw;
        }
    }

    [[nodiscard]] int GetMaxIntSize() const { return maxIntSize; }
    void SetMaxIntSize(const int& value) { maxIntSize = value; }

protected:
    void Update() override;
    void Draw() override;

private:
    InputTypes inputType{InputTypes::INT};
    int maxIntSize{999999999};
};


#endif //INPUT_H
