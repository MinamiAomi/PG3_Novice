#pragma once
#include <memory>
#include <string>

class IScene;

class SceneManager {
public:
    static void Create();
    static void Update();
    static void Draw();
    template<class T, class... Args>
    static void ChangeScene(const Args&... args) {
        static_assert(std::is_base_of<IScene, T>::value, "Not inherite IScene!");
        s_sceneManager->m_standbyScene = std::make_unique<T>(args...);
    }
    static std::string GetActiveSceneName();

private:
    static std::unique_ptr<SceneManager> s_sceneManager;

    SceneManager() = default;
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;


    std::unique_ptr<IScene> m_activeScene;  // 現在のシーン
    std::unique_ptr<IScene> m_standbyScene; // 遷移待ちシーン
};