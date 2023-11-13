#pragma once
#include "IScene.h"
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

class StageScene :
    public IScene {
public:
    void OnInitialize() override;
    void OnUpdate() override;
    void OnDraw() override;

    std::string GetName() const override { return "StageScene"; }

private:
    Player m_player;
    std::vector<Enemy> m_enemys;
    BulletManager m_bulletManager;
};