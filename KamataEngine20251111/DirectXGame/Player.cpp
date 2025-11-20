#include "Player.h"

using namespace KamataEngine;

void Player::Initialize() {
	worldTransform_.Initialize();
	model_ = Model::CreateSphere();
}

void Player::Update() {}

void Player::Draw(const Camera& camera) { model_->Draw(worldTransform_, camera); }
