#include "InputHandler.h"

#include "InputManager.h"
#include "Novice.h"

ICommand* InputHandler::HandleInput() {
    auto inputManager = InputManager::GetInstance();
    if (inputManager->IsPressed(DIK_A)) {
        return m_pressKeyA.get();
    }
    if (inputManager->IsPressed(DIK_D)) {
        return m_pressKeyD.get();
    }
    return nullptr;
}

void InputHandler::AssignMoveLeftCommandToPressKeyA() {
    m_pressKeyA = std::make_unique<MoveLeftCommand>();
}

void InputHandler::AssignMoveRightCommandToPressKeyD() {
    m_pressKeyD = std::make_unique<MoveRightCommand>();
}
