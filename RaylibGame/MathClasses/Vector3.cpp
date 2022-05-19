#include "Vector3.h"
#include <cmath>
Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
};
Vector3::~Vector3() {
}
inline Vector3 Vector3::operator+(Vector3 a) {
	return Vector3(x + a.x, y + a.y, z + a.z);
}
inline Vector3 Vector3::operator-(Vector3 a) {
	return Vector3(x - a.x, y - a.y, z - a.z);
}
inline Vector3 Vector3::operator*(float f) {
	return Vector3(x * f, y * f, z * f);
}
inline Vector3 Vector3::operator/(float f) {
	Vector3(x / f, y / f, z / f);
}
inline bool Vector3::operator==(Vector3 a) {
	if (a.x == x && a.y == y && a.z == z)
	{
		return true;
	}
	else return false;
}
inline bool Vector3::operator!=(Vector3 a) {
	if (a.x == x && a.y == y && a.z == z)
	{
		return false;
	}
	else return true;
}
float Vector3::Magnitude() {
	float thismagnitude = Dot(*this);
	thismagnitude = (float)sqrt(thismagnitude);
	return thismagnitude;
}
float Vector3::Dot(Vector3 a) {
	float dot = (x * a.x) + (y * a.y) + (z * a.z);
	return dot;
}
Vector3 Vector3::Cross(Vector3 a) {
	return Vector3(
		((y * a.z) - (z * a.y)),
		((z * a.x) - (x * a.z)),
		((x * a.y) - (y * a.x))
	);
}
Vector3 Vector3::Normalise() {
	float mag = this->Magnitude();
	return Vector3(x / mag, y / mag, z / mag);
}
Vector3 Vector3::Min(Vector3 a) {
	return Vector3(fmin(x, a.x), fmin(y, a.y), fmin(z, a.z));
}
Vector3 Vector3::Max(Vector3 a) {
	return Vector3(fmax(x, a.x), fmax(y, a.y), fmax(z, a.z));
}
Vector3 Vector3::Clamp(Vector3 t, Vector3 a, Vector3 b) {
	return a.Max(b.Min(t));
}