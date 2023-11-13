#include "ClearScene.h"
#include "Novice.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TitleScene.h"

#include <filesystem>

void ClearScene::OnInitialize() {
}

void ClearScene::OnUpdate() {
    if (InputManager::GetInstance()->IsTrigger(DIK_SPACE)) {
        SceneManager::ChangeScene<TitleScene>();
    }
}

void ClearScene::OnDraw() {
    Novice::ScreenPrintf(0, 0, "Clear");
}
