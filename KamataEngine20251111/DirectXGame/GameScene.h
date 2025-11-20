#pragma once
#include "IScene.h"
#include <KamataEngine.h>

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
	KamataEngine::Camera camera_;
};
