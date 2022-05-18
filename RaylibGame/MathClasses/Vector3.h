#pragma once
struct Vector3 {
	float x;
	float y;
	float z;
public:
	inline Vector3 operator+(Vector3 a);
	inline Vector3 operator-(Vector3 a);
	inline Vector3 operator*(float);
	inline Vector3 operator/(float);
	inline Vector3 operator=(Vector3 a);
	inline Vector3 operator==(Vector3 a);
	inline Vector3 operator!=(Vector3 a);
	float Magnitude();
	float MagnitudeSqr();
	float Dot(Vector3 a);
	Vector3 Cross(Vector3 a);
	Vector3 Normalise();
	static Vector3 Min(Vector3 a, Vector3 b);
	static Vector3 Max(Vector3 a, Vector3 b);
	static Vector3 Clamp(Vector3 t, Vector3 a, Vector3 b);
};
