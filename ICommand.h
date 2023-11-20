#pragma once
#include "Player.h"
class Player;

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void Excute(Player& player) = 0;
};

class MoveRightCommand : public ICommand {
public:
    void Excute(Player& player) override {
        player.MoveRight();
    }
};

class MoveLeftCommand : public ICommand {
public:
    void Excute(Player& player) override {
        player.MoveLeft();
    }
};
