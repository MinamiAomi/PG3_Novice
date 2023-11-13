#include "InputManager.h"
#include "Novice.h"

InputManager* InputManager::GetInstance() {
    static InputManager instance;
    return &instance;
}

void InputManager::Update() {
    // キー入力を受け取る
    memcpy(m_preKeys, m_keys, 256);
    Novice::GetHitKeyStateAll(m_keys);
}

bool InputManager::IsTrigger(char keycode) const { return m_preKeys[keycode] == 0 && m_keys[keycode] != 0; }
bool InputManager::IsPressed(char keycode) const { return m_keys[keycode] != 0; }
bool InputManager::IsRelease(char keycode) const { return m_preKeys[keycode] != 0 && m_keys[keycode] == 0; }