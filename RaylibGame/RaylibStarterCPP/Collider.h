#pragma once
#include "Vector3.h"
#include <vector>
#include "raylib.h"
using namespace std;
class Collider {
public:
	Collider();
	MyVector origin;
};
class AABB : Collider {
public:
	MyVector extents;
	MyVector Max{origin + extents};
	MyVector Min{origin - extents};
	AABB();
	AABB(MyVector  center, float width, float height);
	bool IsEmpty();
	void Empty();
	vector<MyVector> Corners();
	bool Overlaps(MyVector p);
	bool Overlaps(AABB other);
	MyVector ClosestPoint(MyVector p);
	void DrawBox();
	bool Intersects(Collider other);
};
class Sphere : Collider {
public:
	float radius;
	Sphere();
	Sphere(MyVector c, float r);
	void Fit();
	bool Overlaps(MyVector p);
	bool Overlaps(Sphere other);
	bool Overlaps(AABB aabb);
	MyVector ClosestPoint(MyVector p);
	void Drawsphere(Color colour);
	bool Intersects(Collider other);
};
class Plane : Collider {
public:
	float d;
	Plane();
	Plane(MyVector n, float d);
	float DistanceTo(MyVector p);
	MyVector VlosestPoint();
	enum ePlaneResult : int {
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};
	ePlaneResult TestSide(MyVector p);
	ePlaneResult TestSide(Sphere sphere);
	ePlaneResult TestSide(AABB aabb);
	bool Intersects(Collider other);
	void DrawPlane();
};