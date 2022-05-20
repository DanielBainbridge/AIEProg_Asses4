#pragma once
#include "Vector3.h"
struct Matrix3 {
public:
	float m00, m01, m02;
	float m10, m11, m12;
	float m20, m21, m22;
	Matrix3();
	Matrix3(float m00f, float m01f, float m02f, float m10f, float m11f, float m12f, float m20f, float m21f, float m22f);
	Matrix3(float uniscale);
	~Matrix3();
	inline Matrix3 operator*(Matrix3& a);
	inline MyVector operator*(MyVector& a);
	Matrix3 SetTranslation(float x, float y);
	void Translate(MyVector v);
	Matrix3 SetRotateX(double rad);
	Matrix3 SetRotateY(double rad);
	Matrix3 SetRotateZ(double rad);
	void Set(Matrix3 m);
};
