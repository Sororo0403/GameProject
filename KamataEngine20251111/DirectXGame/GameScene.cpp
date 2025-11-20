#include "GameScene.h"
#include "CameraUtility.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	// デバッグカメラ
	debugCamera_ = std::make_unique<DebugCamera>(WinApp::kWindowWidth, WinApp::kWindowHeight);

	// カメラ
	camera_.Initialize();
}

void GameScene::Update() {
	// デバッグカメラ
	debugCamera_->Update();

	// カメラ
	CameraUtility::Update(camera_);
}

void GameScene::Draw() {}
