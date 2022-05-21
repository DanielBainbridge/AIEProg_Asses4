#include "Collider.h"
//collider default constructor
Collider::Collider() {origin = MyVector(0, 0, 0);}
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
bool AABB::Overlaps(MyVector p) {
}
bool AABB::Overlaps(AABB other) {
}
MyVector AABB::ClosestPoint(MyVector p) {
}
void AABB::DrawBox() {
}
bool AABB::Intersects(Collider other) {
}
//sphere section
Sphere::Sphere(){
}
Sphere::Sphere(MyVector c, float r){
}
void Sphere::Fit(){
}
bool Sphere::Overlaps(MyVector p){
}
bool Sphere::Overlaps(Sphere other){
}
bool Sphere::Overlaps(AABB aabb){
}
MyVector Sphere::ClosestPoint(MyVector p){
}
void Sphere::Drawsphere(Color colour){
}
bool Sphere::Intersects(Collider other){
}
//plane section
Plane::Plane(){
}
Plane::Plane(MyVector n, float d){
}
float Plane::DistanceTo(MyVector p){
}
MyVector Plane::VlosestPoint(){
}
Plane::ePlaneResult Plane::TestSide(MyVector p){
}
Plane::ePlaneResult Plane::TestSide(Sphere sphere){
}
Plane::ePlaneResult Plane::TestSide(AABB aabb){
}
bool Plane::Intersects(Collider other){
}
void Plane::DrawPlane(){
}