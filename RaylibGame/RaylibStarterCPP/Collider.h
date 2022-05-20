#pragma once
#include "Vector3.h"
class Collider {
public:
	MyVector origin;
};
class AABB : Collider {
public:
	MyVector extents;
	MyVector Max{origin + extents};
	MyVector Min{origin - extents};
};
class Sphere : Collider {

};
class Plane : Collider {

};