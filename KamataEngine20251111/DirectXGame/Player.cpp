#include "Player.h"
#include "WorldTransformUtility.h"

using namespace KamataEngine;

void Player::Initialize() {
	worldTransform_.Initialize();
	model_ = Model::Create();
}

void Player::Update() {
	Move();
	WorldTransformUtility::ApplyMatrix(worldTransform_);
}

void Player::Draw(const Camera& camera) { model_->Draw(worldTransform_, camera); }

void Player::Move() {
	Input* input = Input::GetInstance();

	if (input->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= speed_;
	}
	if (input->PushKey(DIK_D)) {
		worldTransform_.translation_.x += speed_;
	}
}
