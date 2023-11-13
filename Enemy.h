#pragma once
#include "CollisionObject.h"

class Enemy :
    public CollisionObject {
public:
    void Initialize(int posX, int posY);

    void Update();
    void Draw();

    bool IsAlive() const { return m_isAlive; }

    int GetPosX() const override { return m_posX; }
    int GetPosY() const override { return m_posY; }
    int GetRadius() const override { return kRadius; }
    void OnCollision() override;

private:
    static constexpr int kSpeedX = 2;
    static constexpr int kRadius = 25;

    int m_posX;
    int m_posY;
    int m_velX;
    bool m_isAlive;
};