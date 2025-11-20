#include "GameScene.h"
#include "CameraUtility.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	debugCamera_ = std::make_unique<DebugCamera>(WinApp::kWindowWidth, WinApp::kWindowHeight);
	camera_.Initialize();

	model_ = Model::Create();
}

void GameScene::Update() {
	debugCamera_->Update();
	CameraUtility::Update(camera_);
}

void GameScene::Draw() {}
