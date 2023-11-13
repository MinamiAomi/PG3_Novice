#include "Enemy.h"

#include "Novice.h"
#include "GameSetting.h"

void Enemy::Initialize(int posX, int posY) {
    m_posX = posX;
    m_posY = posY;
    m_velX = kSpeedX;
    m_isAlive = true;
}

void Enemy::Update() {
    m_posX += m_velX;

    if (m_posX - kRadius <= 0 || 
        m_posX + kRadius > kStageWidth) {
        m_velX *= -1;
    }
}

void Enemy::Draw() {
    Novice::DrawEllipse(m_posX, m_posY, kRadius, kRadius, 0.0f, RED, kFillModeSolid);
}

void Enemy::OnCollision() {
    m_isAlive = false;
}
