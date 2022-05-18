#pragma once
#include "Vector3.h"
struct Matrix3 {
public:
	float m00, m01, m02;
	float m10, m11, m12;
	float m20, m21, m22;
	Matrix3(float uniscale) {};
	inline Matrix3 operator*(Matrix3 a);
	inline Matrix3 operator*(Vector3 a);
	Matrix3 SetTranslation(float x, float y);
	void Translate(Vector3 v);
	Matrix3 SetRotateX(double rad);
	Matrix3 SetRotateY(double rad);
	Matrix3 SetRotateZ(double rad);
	void Set(Matrix3 m);
};