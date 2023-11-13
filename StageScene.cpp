#include "StageScene.h"
#include "Novice.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ClearScene.h"

void StageScene::OnInitialize() {
    m_player.Initialize(&m_bulletManager);

    constexpr int kNumEnemeys = 5;
    constexpr int kBaseX = 300;
    constexpr int kBaseY = 100;
    constexpr int kDistanceX = 100;
    constexpr int kDistanceY = 50;

    m_enemys.resize(kNumEnemeys);
    for (int i = 0; i < kNumEnemeys; ++i) {
        m_enemys[i].Initialize(kBaseX + kDistanceX * i, kBaseY + kDistanceY * i);
    }

}

void StageScene::OnUpdate() {

    m_player.Update();
    for (auto& enemy : m_enemys) {
        if (enemy.IsAlive()) {
            enemy.Update();
        }
    }
    m_bulletManager.Update();

    auto CheckCollision = [](CollisionObject& co1, CollisionObject& co2) {
        int vx = co2.GetPosX() - co1.GetPosX();
        int vy = co2.GetPosY() - co1.GetPosY();
        int length = vx * vx + vy * vy;
        int maxLength = (co1.GetRadius() + co2.GetRadius()) * (co1.GetRadius() + co2.GetRadius());
        if (length < maxLength) {
            co1.OnCollision();
            co2.OnCollision();
        }
    };

    for (auto& enemy : m_enemys) {
        if (enemy.IsAlive()) {
            CheckCollision(m_player, enemy);
            for (auto& bullet : m_bulletManager.GetBullet()) {
                CheckCollision(enemy, *bullet);
            }
        }
    }

    int enemyCount = 0;
    for (auto& enemy : m_enemys) {
        if (enemy.IsAlive()) {
            ++enemyCount;
        }
    }
    if (enemyCount <= 0) {
        SceneManager::ChangeScene<ClearScene>();
    }
}

void StageScene::OnDraw() {
    Novice::ScreenPrintf(0, 0, "Stage");

    m_player.Draw();
    for (auto& enemy : m_enemys) {
        if (enemy.IsAlive()) {
            enemy.Draw();
        }
    }
    m_bulletManager.Draw();
}
