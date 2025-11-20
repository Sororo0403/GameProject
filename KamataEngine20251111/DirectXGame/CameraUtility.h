#pragma once
#include <KamataEngine.h>

namespace CameraUtility {

/// <summary>
/// カメラの行列を適用
/// </summary>
/// <param name="camera">適用を行う、カメラの参照</param>
inline void ApplyMatrix(KamataEngine::Camera& camera) {
	camera.UpdateMatrix();
	camera.TransferMatrix();
}

/// <summary>
/// カメラのデフォルト設定
/// </summary>
/// <param name="camera">設定を行う、カメラの参照</param>
inline void SetupDefault(KamataEngine::Camera& camera) {
	camera.translation_ = {0.0f, 0.0f, -5.0f};
	camera.rotation_ = {0.0f, 0.0f, 0.0f};

	camera.fovAngleY = 0.45f;
	camera.aspectRatio = float(KamataEngine::WinApp::kWindowWidth) / float(KamataEngine::WinApp::kWindowHeight);

	camera.nearZ = 0.1f;
	camera.farZ = 1000.0f;
}

} // namespace CameraUtility
