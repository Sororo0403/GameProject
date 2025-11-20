#pragma once
#include "MatrixUtility.h"
#include <KamataEngine.h>

namespace WorldTransformUtility {

/// <summary>
/// ワールドトランスフォームの行列を適用
/// </summary>
/// <param name="camera">適用を行う、ワールドトランスフォームの参照</param>
inline void ApplyMatrix(KamataEngine::WorldTransform& worldTransform) {
	worldTransform.matWorld_ = MatrixUtility::MakeAffineMatrix(worldTransform.scale_, worldTransform.rotation_, worldTransform.translation_);
	worldTransform.TransferMatrix();
}

} // namespace WorldTransformUtility
