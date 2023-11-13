#pragma once
#include "CollisionObject.h"

#include "GameSetting.h"

class Bullet :
    public CollisionObject {
public:
    void Initialize(int posX, int posY);

    void Update();
    void Draw();

    bool IsDead() const { return m_isDead; }

    int GetPosX() const override { return m_posX; }
    int GetPosY() const override { return m_posY; }
    int GetRadius() const override { return kRadius; }

    void OnCollision() override;

private:
    static constexpr int kSpeedY = 5;
    static constexpr int kRadius = 10;

    int m_posX;
    int m_posY;
    bool m_isDead;
};