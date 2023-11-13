#include <Novice.h>
#include "GameSetting.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TitleScene.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

    InputManager* inputManager = InputManager::GetInstance();

    SceneManager::Create();
    SceneManager::ChangeScene<TitleScene>();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        inputManager->Update();

        ///
        /// ↓更新処理ここから
        ///
        SceneManager::Update();
        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///
        SceneManager::Draw();
        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (inputManager->IsTrigger(DIK_ESCAPE)) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
