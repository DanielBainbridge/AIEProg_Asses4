#include "Matrix3.h"
#include <cmath>
Matrix3::Matrix3() { 0, 0, 0, 0, 0, 0, 0, 0, 0; }
Matrix3::Matrix3(float m00f, float m01f, float m02f, float m10f, float m11f, float m12f, float m20f, float m21f, float m22f) {
    m00 = m00f;
    m01 = m01f;
    m02 = m02f;
    m10 = m10f;
    m11 = m11f;
    m12 = m12f;
    m20 = m20f;
    m21 = m21f;
    m22 = m22f;
}
Matrix3::Matrix3(float uniscale) {
	m00 = m11 = m22 = uniscale;
	m01 = m02 = m10 = m12 = m20 = m21 = 0;
}
Matrix3::~Matrix3() {
}
inline Matrix3 Matrix3::operator*(Matrix3 &a) {
	return Matrix3(
        (a.m00 * m00) + (a.m01 * m10) + (a.m02 * m20),
        (a.m00 * m01) + (a.m01 * m11) + (a.m02 * m21),
        (a.m00 * m02) + (a.m01 * m12) + (a.m02 * m22),

        (a.m10 * m00) + (a.m11 * m10) + (a.m12 * m20),
        (a.m10 * m01) + (a.m11 * m11) + (a.m12 * m21),
        (a.m10 * m02) + (a.m11 * m12) + (a.m12 * m22),

        (a.m20 * m00) + (a.m21 * m10) + (a.m22 * m20),
        (a.m20 * m01) + (a.m21 * m11) + (a.m22 * m21),
        (a.m20 * m02) + (a.m21 * m12) + (a.m22 * m22)
	);
}
inline Vector3 Matrix3::operator*(Vector3 &a) {
    return Vector3(
        (m00 * a.x) + (m10 * a.y) + (m20 * a.z),
        (m01 * a.x) + (m11 * a.y) + (m21 * a.z),
        (m02 * a.x) + (m12 * a.y) + (m22 * a.z)
    );
}
Matrix3 Matrix3::SetTranslation(float x, float y) {
    m20 = x; m21 = y;
    return *this;
}
void Matrix3::Translate(Vector3 v) {
    Matrix3 m = Matrix3(1);
    m.SetTranslation(v.x, v.y);
    Set(*this * m);
}
Matrix3 Matrix3::SetRotateX(double rad) {
    *this = Matrix3(
        1, 0, 0,
        0, (float)cos(rad), (float)sin(rad),
        0, (float)-sin(rad), (float)cos(rad));
    return *this;
}
Matrix3 Matrix3::SetRotateY(double rad) {
    *this = Matrix3(
        (float)cos(rad), 0, (float)-sin(rad),
        0, 1, 0,
        (float)sin(rad), 0, (float)cos(rad));
    return *this;
}
Matrix3 Matrix3::SetRotateZ(double rad) {
    *this = Matrix3(
        (float)cos(rad), (float)sin(rad), 0,
        (float)-sin(rad), (float)cos(rad), 0,
        0, 0, 1);    
    return *this;
}
void Matrix3::Set(Matrix3 m) {
    m00 = m.m00;
    m01 = m.m01;
    m02 = m.m02;
    m10 = m.m10;
    m11 = m.m11;
    m12 = m.m12;
    m20 = m.m20;
    m21 = m.m21;
    m22 = m.m22;
}