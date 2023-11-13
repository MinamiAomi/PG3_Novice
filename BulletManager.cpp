#include "BulletManager.h"

void BulletManager::AddBullet(int posX, int posY) {
    auto& bullet = m_bullets.emplace_back(new Bullet);
    bullet->Initialize(posX, posY);
}

void BulletManager::Update() {
    std::erase_if(m_bullets, [](auto& bullet) {return bullet->IsDead(); });
    
    for (auto& bullet : m_bullets) {
        bullet->Update();
    }
}

void BulletManager::Draw() {
    for (auto& bullet : m_bullets) {
        bullet->Draw();
    }
}
