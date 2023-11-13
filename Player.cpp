#include "Player.h"
#include "Novice.h"
#include "InputManager.h"
#include "BulletManager.h"

void Player::Initialize(BulletManager* bulletManager) {
    m_posX = kStartPosX;
    m_posY = kStartPosY;
    m_bulletManager = bulletManager;
}

void Player::Update() {
    InputManager* inputManager = InputManager::GetInstance();

    if (inputManager->IsPressed(DIK_D)) {
        m_posX += kSpeedX;
    }
    if (inputManager->IsPressed(DIK_A)) {
        m_posX += -kSpeedX;
    }

    if (inputManager->IsPressed(DIK_W)) {
        m_posY += -kSpeedY;
    }
    if (inputManager->IsPressed(DIK_S)) {
        m_posY += kSpeedY;
    }

    if (inputManager->IsTrigger(DIK_SPACE)) {
        m_bulletManager->AddBullet(m_posX, m_posY);
    }
}

void Player::Draw() {
    Novice::DrawEllipse(m_posX, m_posY, kRadius, kRadius, 0.0f, WHITE, kFillModeSolid);
}

