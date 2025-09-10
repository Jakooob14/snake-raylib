#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H



class GameComponent
{
public:
    virtual ~GameComponent() = default;

    [[nodiscard]] bool IsDestroyed() const { return destroyed; }
    void Destroy() { destroyed = true; }

    [[nodiscard]] bool IsInitialized() const { return initialized; }

protected:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Initialize() { initialized = true; }

    friend class Screen;

private:
    bool destroyed{false};
    bool initialized{false};
};



#endif //GAMECOMPONENT_H
