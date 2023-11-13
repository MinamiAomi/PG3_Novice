#pragma once
#include "CollisionObject.h"

#include "GameSetting.h"

class BulletManager;

class Player :
    public CollisionObject {
public:
    void Initialize(BulletManager* bulletManager);

    void Update();
    void Draw();

    int GetPosX() const override { return m_posX; }
    int GetPosY() const override { return m_posY; }
    int GetRadius() const override { return kRadius; }

private:
    static constexpr int kSpeedX = 3;
    static constexpr int kSpeedY = 3;
    static constexpr int kRadius = 25;
    static constexpr int kStartPosX = kStageWidth / 2;
    static constexpr int kStartPosY = 600;

    int m_posX;
    int m_posY;

    BulletManager* m_bulletManager;
};