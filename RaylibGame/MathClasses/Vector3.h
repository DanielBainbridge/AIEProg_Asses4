#pragma once
struct MyVector {
	float x;	float y;	float z;
public:
	MyVector(float x, float y, float z);
	~MyVector();
	MyVector operator+(MyVector a);
	MyVector operator-(MyVector a);
	MyVector operator*(float f);
	MyVector operator/(float f);
	bool operator==(MyVector a);
	bool operator!=(MyVector a);
	float Magnitude();
	float Dot(MyVector a);
	MyVector Cross(MyVector a);
	MyVector Normalise();
	MyVector Min(MyVector a);
	MyVector Max(MyVector a);
	MyVector Clamp(MyVector t, MyVector a, MyVector b);
};

