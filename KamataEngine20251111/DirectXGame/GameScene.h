#pragma once
#include "IScene.h"
#include "Player.h"
#include <KamataEngine.h>
#include <memory>

class GameScene : public IScene {
public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

private:
	std::unique_ptr<KamataEngine::DebugCamera> debugCamera_;
	KamataEngine::Camera camera_;

	std::unique_ptr<Player> player_;
};
