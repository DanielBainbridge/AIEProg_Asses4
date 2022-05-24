#pragma once
#include "raylib.h"
#include <vector>
#include "Matrix3.h"
#include "Vector3.h"
#include "Collider.h"
using namespace std;
class GameObject{
public:
	vector<GameObject*> children;
	vector<GameObject*> childrenAddPending;
	vector<GameObject*> childrenRemovePending;
protected:
	GameObject* parent = nullptr;
	Matrix3 localTransform;
	Matrix3 globalTransform;
public:
	void AddChild(GameObject* child);
	void RemoveChild(GameObject* child);
	void RemoveFromParent();
	void CopyTransformToLocal(Matrix3 t);
	MyVector GlobalTransformAsVector();
	void UpdateTransform();
	void SetPosition(float x, float y);
	void SetRotate(float radians);
	void Rotate(float radians);
	void Translate(MyVector v);
	void TranslateLocal(MyVector v);
	MyVector DistanceTo(GameObject obj);
	virtual void OnUpdate(float deltatime);
	virtual void OnDraw();
	void Update(float deltatime);
	void Draw();
};