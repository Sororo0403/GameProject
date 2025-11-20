#include "SceneManager.h"
#include "TitleScene.h"
#include <KamataEngine.h>
#include <Windows.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// エンジンの初期化
	KamataEngine::Initialize(L"GameProject");

	// DirectXCommon のインスタンス取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 最初のシーンを TitleScene に設定
	SceneManager sceneManager(std::make_unique<TitleScene>());

	// メインループ
	while (true) {
		// エンジン更新（入力更新など）
		if (KamataEngine::Update()) {
			break;
		}

		// シーン更新
		sceneManager.Update();

		// 描画開始
		dxCommon->PreDraw();

		// シーン描画
		sceneManager.Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// 終了処理
	KamataEngine::Finalize();

	return 0;
}
