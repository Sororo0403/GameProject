#pragma once
#include <memory>

class IScene {
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IScene() {}

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;
};
