#include "GameScene.h"
#include "CameraUtility.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	CameraUtility::SetupDefault(camera_);
	camera_.Initialize();

	player_ = std::make_unique<Player>();
	player_->Initialize();
}

void GameScene::Update() {
	CameraUtility::ApplyMatrix(camera_);

	player_->Update();
}

void GameScene::Draw() {
	Model::PreDraw();
	player_->Draw(camera_);
	Model::PostDraw();
}
