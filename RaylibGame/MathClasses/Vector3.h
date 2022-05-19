#pragma once
struct Vector3 {
	float x;
	float y;
	float z;
public:
	Vector3(float x, float y, float z) {};
	~Vector3();
	inline Vector3 operator+(Vector3 a);
	inline Vector3 operator-(Vector3 a);
	inline Vector3 operator*(float f);
	inline Vector3 operator/(float f);
	inline bool operator==(Vector3 a);
	inline bool operator!=(Vector3 a);
	float Magnitude();
	float Dot(Vector3 a);
	Vector3 Cross(Vector3 a);
	Vector3 Normalise();
	Vector3 Min(Vector3 a);
	Vector3 Max(Vector3 a);
	Vector3 Clamp(Vector3 t, Vector3 a, Vector3 b);
};
