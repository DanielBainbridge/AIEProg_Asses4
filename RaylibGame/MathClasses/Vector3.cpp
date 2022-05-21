#include "Vector3.h"
#include <cmath>
MyVector::MyVector() {
	x = y = z = 0;
}
MyVector::MyVector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
};
MyVector::~MyVector() {
}
MyVector MyVector::operator+(MyVector a) {
	return MyVector(x + a.x, y + a.y, z + a.z);
}
MyVector MyVector::operator-(MyVector a) {
	return MyVector(x - a.x, y - a.y, z - a.z);
}
MyVector MyVector::operator*(float f) {
	return MyVector(x * f, y * f, z * f);
}
MyVector MyVector::operator/(float f) {
	return MyVector(x / f, y / f, z / f);
}
bool MyVector::operator==(MyVector a) {
	if (a.x == x && a.y == y && a.z == z)
	{
		return true;
	}
	else return false;
}
bool MyVector::operator!=(MyVector a) {
	if (a.x == x && a.y == y && a.z == z)
	{
		return false;
	}
	else return true;
}
float MyVector::Magnitude() {
	float thismagnitude = Dot(*this);
	thismagnitude = (float)sqrt(thismagnitude);
	return thismagnitude;
}
float MyVector::Dot(MyVector a) {
	float dot = (x * a.x) + (y * a.y) + (z * a.z);
	return dot;
}
MyVector MyVector::Cross(MyVector a) {
	return MyVector(
		((y * a.z) - (z * a.y)),
		((z * a.x) - (x * a.z)),
		((x * a.y) - (y * a.x))
	);
}
MyVector MyVector::Normalise() {
	float mag = this->Magnitude();
	return MyVector(x / mag, y / mag, z / mag);
}
MyVector MyVector::Min(MyVector a) {
	return MyVector(fmin(x, a.x), fmin(y, a.y), fmin(z, a.z));
}
MyVector MyVector::Max(MyVector a) {
	return MyVector(fmax(x, a.x), fmax(y, a.y), fmax(z, a.z));
}
MyVector MyVector::Clamp(MyVector t, MyVector a, MyVector b) {
	return a.Max(b.Min(t));
}