#pragma once
#include <KamataEngine.h>

namespace CameraUtility {

/// <summary>
/// カメラの更新を行う
/// </summary>
/// <param name="camera">更新を行う、カメラの参照</param>
inline void Update(KamataEngine::Camera& camera) {
	camera.UpdateMatrix();
	camera.TransferMatrix();
}

} // namespace CameraUtility
