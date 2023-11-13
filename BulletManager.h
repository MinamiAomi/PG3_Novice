#pragma once
#include <memory>
#include <list>

#include "Bullet.h"

class BulletManager {
public:
    void AddBullet(int posX, int posY);
    void Update();
    void Draw();

    const std::list<std::unique_ptr<Bullet>>& GetBullet() const { return m_bullets; }
    std::list<std::unique_ptr<Bullet>>& GetBullet() { return m_bullets; }

private:
    std::list<std::unique_ptr<Bullet>> m_bullets;
};