#include "TitleScene.h"
#include "Novice.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "StageScene.h"

void TitleScene::OnInitialize() {
}

void TitleScene::OnUpdate() {
    if (InputManager::GetInstance()->IsTrigger(DIK_SPACE)) {
        SceneManager::ChangeScene<StageScene>();
    }
}

void TitleScene::OnDraw() {
    Novice::ScreenPrintf(0, 0, "Title");
}
