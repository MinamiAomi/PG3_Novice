#pragma once

class InputManager {
public:
    static InputManager* GetInstance();
    void Update();
    bool IsTrigger(char keycode) const;
    bool IsPressed(char keycode) const;
    bool IsRelease(char keycode) const;

private:
    char m_keys[256]{};
    char m_preKeys[256]{};
};