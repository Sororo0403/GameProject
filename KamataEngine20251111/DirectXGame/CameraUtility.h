#pragma once
#include <KamataEngine.h>

namespace CameraUtility {

inline void Update(KamataEngine::Camera& camera) {
	camera.UpdateMatrix();
	camera.TransferMatrix();
}

} // namespace CameraUtility
