#include "Bullet.h"
#include "Novice.h"

void Bullet::Initialize(int posX, int posY) {
    m_posX = posX;
    m_posY = posY;
    m_isDead = false;
}

void Bullet::Update() {
    if (m_posY - kRadius < 0) {
        m_isDead = true;
    }

    m_posY -= kSpeedY;
}

void Bullet::Draw() {
    Novice::DrawEllipse(m_posX, m_posY, kRadius, kRadius, 0.0f, BLUE, kFillModeSolid);
}

void Bullet::OnCollision() {
    m_isDead = true;
}
