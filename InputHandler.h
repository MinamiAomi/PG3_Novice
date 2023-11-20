#pragma once
#include "ICommand.h"

#include <memory>

class InputHandler {
public:
    ICommand* HandleInput();

    void AssignMoveLeftCommandToPressKeyA();
    void AssignMoveRightCommandToPressKeyD();

private:
    std::unique_ptr<ICommand> m_pressKeyD;
    std::unique_ptr<ICommand> m_pressKeyA;
};