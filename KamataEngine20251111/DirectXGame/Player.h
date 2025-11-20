#pragma once
#include <KamataEngine.h>

class Player {
public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="camera">描画を行う、カメラの参照</param>
	void Draw(const KamataEngine::Camera& camera);

private:
	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;

	float speed_ = 0.5f;
};