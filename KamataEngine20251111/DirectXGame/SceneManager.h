#pragma once
#include "IScene.h"
#include <memory>

class SceneManager {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManager(std::unique_ptr<IScene> startScene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 新しいシーンへ切り替える
	/// </summary>
	void ChangeScene(std::unique_ptr<IScene> newScene);

private:
	std::unique_ptr<IScene> currentScene_;
};
