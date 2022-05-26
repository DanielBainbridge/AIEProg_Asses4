#include "Collider.h"
#include <cmath>
//collider default constructor
Collider::Collider() { origin = MyVector(0, 0, 0); }
Collider::~Collider() {
}
//AABB section
AABB::AABB() {
	this->origin = MyVector(0, 0, 0);
	this->extents = MyVector(0, 0, 0);
}
AABB::AABB(MyVector  center, float width, float height) {
	this->origin = center;
	this->extents = MyVector(0.5f * width, 0.5f * height, 0);
}

bool AABB::IsEmpty() {
	if (extents == MyVector(0, 0, 0))
		return true;
	return false;
}
void AABB::Empty() {
	extents = MyVector(0, 0, 0);
}
vector<MyVector> AABB::Corners() {
	vector<MyVector> corners;
	corners.push_back(Min);
	corners.push_back(MyVector(Min.x, Max.y, Min.z));
	corners.push_back(Max);
	corners.push_back(MyVector(Max.x, Min.y, Min.z));
	return corners;
}
void AABB::Fit(vector<MyVector*> points) {
	MyVector min = MyVector(INFINITY, INFINITY, INFINITY);
	MyVector max = MyVector(INFINITY * -1, INFINITY * -1, INFINITY * -1);
	for (MyVector* p : points) {
		min = min.Min(*p);
		max = max.Max(*p);
	}
	origin = (min + max) * 0.5f;
	extents = max - origin;
}
bool AABB::Overlaps(MyVector p) {
	return !(p.x < Min.x || p.y < Min.y || p.x > Max.x || p.y > Max.y);
}
bool AABB::Overlaps(AABB other) {
	return !(other.Max.x < Min.x || other.Max.y < Min.y || other.Min.x > Max.x || other.Min.y > Max.y);
}
MyVector AABB::ClosestPoint(MyVector p) {
	MyVector cp = cp.Clamp(p, Min, Max);
	return cp;
}
void AABB::DrawBox() {
	DrawLine((int)this->Corners()[0].x, (int)this->Corners()[0].y, (int)this->Corners()[1].x, (int)this->Corners()[1].y, YELLOW);
	DrawLine((int)this->Corners()[1].x, (int)this->Corners()[1].y, (int)this->Corners()[2].x, (int)this->Corners()[2].y, YELLOW);
	DrawLine((int)this->Corners()[2].x, (int)this->Corners()[2].y, (int)this->Corners()[3].x, (int)this->Corners()[3].y, YELLOW);
	DrawLine((int)this->Corners()[3].x, (int)this->Corners()[3].y, (int)this->Corners()[0].x, (int)this->Corners()[0].y, YELLOW);
}
bool AABB::Intersects(Collider* other) {
	AABB* otherbox = dynamic_cast<AABB*>(other);
	if (otherbox != nullptr)
	{
		bool result = this->Overlaps(*otherbox);
		return result;
	}
	else return false;
}
//sphere section
Sphere::Sphere() {
	origin = MyVector(0, 0, 0);
	radius = 0;
}
Sphere::Sphere(MyVector c, float r) {
	origin = c;
	radius = r;
}
void Sphere::Fit(vector<MyVector> points) {
	MyVector Min = MyVector(INFINITY, INFINITY, INFINITY);
	MyVector Max = MyVector(INFINITY * -1, INFINITY * -1, INFINITY * -1);
	for (MyVector p : points) {
		Min = Min.Min(p);
		Max = Min.Max(p);
	}
	origin = (Min + Max) * 0.5f;
	MyVector V = Max - origin;
	radius = V.Dot(V);
}
bool Sphere::Overlaps(MyVector p) {
	MyVector toPoint = p - origin;
	return bool(toPoint.Dot(toPoint) <= (radius * radius));
}
bool Sphere::Overlaps(Sphere other) {
	MyVector diff = other.origin - origin;
	float r = radius + other.radius;
	return bool(diff.Dot(diff) <= (r * r));
}
bool Sphere::Overlaps(AABB aabb) {
	MyVector diff = aabb.ClosestPoint(origin) - origin;
	return bool(diff.Dot(diff) <= (radius * radius));
}
MyVector Sphere::ClosestPoint(MyVector p) {
	MyVector topoint = p - origin;
	if (topoint.Dot(topoint) > radius * radius)
	{
		topoint = topoint.Normalise() * radius;
	}
	return origin + topoint;
}
void Sphere::DrawSphere(Color colour) {
	DrawCircle((int)origin.x, (int)origin.y, radius, colour);
}
bool Sphere::Intersects(Collider* other) {
	AABB* otherbox = dynamic_cast<AABB*>(other);
	Sphere* othersphere = dynamic_cast<Sphere*>(other);
	if (otherbox != nullptr) {
		bool result = this->Overlaps(*otherbox);
		return result;
	}
	else if (othersphere != nullptr) {
		bool result = this->Overlaps(*othersphere);
		return result;
	}
}
//plane section
Plane::Plane() {
	origin = MyVector(0, 0, 0);
	d = 0;
}
Plane::Plane(MyVector n, float d) {
	origin = n;
	this->d = d;
}
float Plane::DistanceTo(MyVector p) {
	return p.Dot(origin) + d;
}
MyVector Plane::ClosestPoint(MyVector p) {
	return p - origin * DistanceTo(p);
}
Plane::ePlaneResult Plane::TestSide(MyVector p) {
	float t = p.Dot(origin) + d;
	if (t < 0)
	{
		return Plane::BACK;
	}
	else if (t > 0)
	{
		return Plane::FRONT;
	}
	return Plane::INTERSECTS;
}
Plane::ePlaneResult Plane::TestSide(Sphere sphere) {
	float t = DistanceTo(sphere.origin);
	if (t > sphere.radius)
	{
		return Plane::FRONT;
	}
	if (t < sphere.radius)
	{
		return Plane::BACK;
	}
	return Plane::INTERSECTS;
}
Plane::ePlaneResult Plane::TestSide(AABB aabb) {
	bool side[] = {false, false};
	for(MyVector c : aabb.Corners())
	{
		ePlaneResult result = TestSide(c);
		if (result == Plane::FRONT)
		{
			side[0] = true;
		}
		if (result == Plane::BACK)
		{
			side[1] = true;
		}
	}
	if (side[0] && !side[1])
	{
		return Plane::FRONT;
	}
	else if (!side[0] && side[1])
	{
		return Plane::BACK;
	}
	return Plane::INTERSECTS;
}
bool Plane::Intersects(Collider* other) {
	AABB* otherbox = dynamic_cast<AABB*>(other);
	Sphere* othersphere = dynamic_cast<Sphere*>(other);
	if (otherbox != nullptr) {
		bool result = this->TestSide(*otherbox);
		return result;
	}
	else if (otherbox != nullptr) {
		bool result = this->TestSide(*otherbox);
		return result;
	}
	else return false;
}
void Plane::DrawPlane() {
	MyVector center = MyVector(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 1);
	Sphere middle = Sphere(this->ClosestPoint(center), 5);
	{
		DrawLine((int)(middle.origin.x - (origin.y * 400)), (int)(middle.origin.y - (origin.x * 400)), (int)(middle.origin.x + (origin.y * 400)), (int)(middle.origin.y + (origin.x * 400)), YELLOW);
	}
	middle.DrawSphere(YELLOW);
}