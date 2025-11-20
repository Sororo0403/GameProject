#include "GameScene.h"
#include "CameraUtility.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	debugCamera_ = std::make_unique<DebugCamera>(WinApp::kWindowWidth, WinApp::kWindowHeight);
	camera_.Initialize();

	player_ = std::make_unique<Player>();
	player_->Initialize();
}

void GameScene::Update() {
	debugCamera_->Update();
	CameraUtility::Update(camera_);
}

void GameScene::Draw() {
	Model::PreDraw();
	player_->Draw(camera_);
	Model::PostDraw();
}
