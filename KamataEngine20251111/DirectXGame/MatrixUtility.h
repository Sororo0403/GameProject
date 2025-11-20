#pragma once
#include <KamataEngine.h>
#include <cmath>

namespace MatrixUtility {

/// <summary>
/// 4×4 の単位行列の作成
/// </summary>
/// <returns>単位行列</returns>
inline KamataEngine::Matrix4x4 MakeIdentity4x4() {
	KamataEngine::Matrix4x4 m{};

	m.m[0][0] = 1.0f;
	m.m[1][1] = 1.0f;
	m.m[2][2] = 1.0f;
	m.m[3][3] = 1.0f;

	return m;
}

/// <summary>
/// 4×4 行列の乗算
/// </summary>
/// <param name="a">左辺の行列 A</param>
/// <param name="b">右辺の行列 B</param>
/// <returns>A × B の行列積</returns>
inline KamataEngine::Matrix4x4 Multiply(const KamataEngine::Matrix4x4& a, const KamataEngine::Matrix4x4& b) {
	KamataEngine::Matrix4x4 result{};

	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			result.m[row][col] = a.m[row][0] * b.m[0][col] + a.m[row][1] * b.m[1][col] + a.m[row][2] * b.m[2][col] + a.m[row][3] * b.m[3][col];
		}
	}

	return result;
}

/// <summary>
/// アフィン変換行列を生成
/// </summary>
/// <param name="scale">拡大率（x, y, z）</param>
/// <param name="rot">回転角（ラジアン表記, x, y, z）</param>
/// <param name="trans">平行移動量（x, y, z）</param>
/// <returns>アフィン変換行列（4×4）</returns>
inline KamataEngine::Matrix4x4 MakeAffineMatrix(const KamataEngine::Vector3& scale, const KamataEngine::Vector3& rot, const KamataEngine::Vector3& trans) {
	using KamataEngine::Matrix4x4;

	// スケール
	Matrix4x4 S = MakeIdentity4x4();
	S.m[0][0] = scale.x;
	S.m[1][1] = scale.y;
	S.m[2][2] = scale.z;

	// 回転 X
	float cx = std::cos(rot.x);
	float sx = std::sin(rot.x);

	Matrix4x4 Rx = MakeIdentity4x4();
	Rx.m[1][1] = cx;
	Rx.m[1][2] = -sx;
	Rx.m[2][1] = sx;
	Rx.m[2][2] = cx;

	// 回転 Y
	float cy = std::cos(rot.y);
	float sy = std::sin(rot.y);

	Matrix4x4 Ry = MakeIdentity4x4();
	Ry.m[0][0] = cy;
	Ry.m[0][2] = sy;
	Ry.m[2][0] = -sy;
	Ry.m[2][2] = cy;

	// 回転 Z
	float cz = std::cos(rot.z);
	float sz = std::sin(rot.z);

	Matrix4x4 Rz = MakeIdentity4x4();
	Rz.m[0][0] = cz;
	Rz.m[0][1] = -sz;
	Rz.m[1][0] = sz;
	Rz.m[1][1] = cz;

	// 回転行列
	Matrix4x4 R = Multiply(Multiply(Rx, Ry), Rz);

	// 平行移動
	Matrix4x4 T = MakeIdentity4x4();
	T.m[0][3] = trans.x;
	T.m[1][3] = trans.y;
	T.m[2][3] = trans.z;

	// 行列の合成
	return Multiply(Multiply(S, R), T);
}

} // namespace MatrixUtility
