#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	// デバッグカメラの生成
	debugCamera_ = std::make_unique<DebugCamera>(WinApp::kWindowWidth, WinApp::kWindowHeight);
}

void GameScene::Update() {
	// デバッグカメラの更新
	debugCamera_->Update();
}

void GameScene::Draw() {}
