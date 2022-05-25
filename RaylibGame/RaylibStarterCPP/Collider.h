#pragma once
#include "Vector3.h"
#include <vector>
#include "raylib.h"
using namespace std;
class Collider {
public:
	Collider();
	virtual ~Collider();
	MyVector origin;
};
class AABB : public Collider {
public:
	MyVector extents;
	MyVector Max{origin + extents};
	MyVector Min{origin - extents};
	AABB();
	AABB(MyVector  center, float width, float height);
	bool IsEmpty();
	void Empty();
	vector<MyVector> Corners();
	void Fit(vector<MyVector*> points);
	bool Overlaps(MyVector p);
	bool Overlaps(AABB other);
	MyVector ClosestPoint(MyVector p);
	void DrawBox();
	bool Intersects(Collider* other);
};
class Sphere : public Collider {
public:
	float radius;
	Sphere();
	Sphere(MyVector c, float r);
	void Fit(vector<MyVector> points);
	bool Overlaps(MyVector p);
	bool Overlaps(Sphere other);
	bool Overlaps(AABB aabb);
	MyVector ClosestPoint(MyVector p);
	void DrawSphere(Color colour);
	bool Intersects(Collider* other);
};
class Plane : public Collider {
public:
	float d;
	Plane();
	Plane(MyVector n, float d);
	float DistanceTo(MyVector p);
	MyVector ClosestPoint(MyVector p);
	enum ePlaneResult : int {
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};
	ePlaneResult TestSide(MyVector p);
	ePlaneResult TestSide(Sphere sphere);
	ePlaneResult TestSide(AABB aabb);
	bool Intersects(Collider* other);
	void DrawPlane();
};