#include "SceneManager.h"
#include "IScene.h"

std::unique_ptr<SceneManager> SceneManager::s_sceneManager;

void SceneManager::Create() {
    s_sceneManager.reset(new SceneManager);
}

void SceneManager::Update() {
    if (s_sceneManager->m_standbyScene) {
        s_sceneManager->m_standbyScene->OnInitialize();
        s_sceneManager->m_activeScene = std::move(s_sceneManager->m_standbyScene);
    }

    if (s_sceneManager->m_activeScene) {
        s_sceneManager->m_activeScene->OnUpdate();
    }
}

void SceneManager::Draw() {
    if (s_sceneManager->m_activeScene) {
        s_sceneManager->m_activeScene->OnDraw();
    }
}

std::string SceneManager::GetActiveSceneName() {
    if (s_sceneManager->m_activeScene) {
        return s_sceneManager->m_activeScene->GetName();
    }
    return std::string();
}
