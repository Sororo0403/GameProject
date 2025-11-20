#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { debugCamera_ = std::make_unique<DebugCamera>(1280, 720); }

void GameScene::Update() { debugCamera_->Update(); }

void GameScene::Draw() {}
