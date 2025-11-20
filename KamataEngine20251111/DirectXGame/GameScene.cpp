#include "GameScene.h"

void GameScene::Initialize() {
	// カメラ初期化
	camera_.translation_ = {0.0f, 0.0f, -5.0f};
	camera_.Initialize();
}

void GameScene::Update() {}

void GameScene::Draw() {}
