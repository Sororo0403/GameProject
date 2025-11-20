#include "SceneManager.h"

SceneManager::SceneManager(std::unique_ptr<IScene> startScene) : currentScene_(std::move(startScene)) {
	if (currentScene_) {
		currentScene_->Initialize();
	}
}

void SceneManager::Update() {
	if (currentScene_) {
		currentScene_->Update();
	}
}

void SceneManager::Draw() {
	if (currentScene_) {
		currentScene_->Draw();
	}
}

void SceneManager::ChangeScene(std::unique_ptr<IScene> newScene) {
	currentScene_ = std::move(newScene);
	if (currentScene_) {
		currentScene_->Initialize();
	}
}
