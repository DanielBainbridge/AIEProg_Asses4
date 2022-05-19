#pragma once
#include "raylib.h"
#include <vector>
#include "Matrix3.h"
#include "Vector3.h"
using namespace std;

class GameObject {
public:
	vector<GameObject> children;
	vector<GameObject> childrenAddPending;
	vector<GameObject> childrenRemovePending;
protected:
	GameObject* parent = nullptr;
	Matrix3 localTransform;
	Matrix3 globalTransform;
public:
	void AddChild(GameObject child);
	void RemoveChild(GameObject child);
	void RemoveFromParent();
	void CopyTransformToLocal(Matrix3 t);
	void UpdateTransform();
	void SetPosition(float x, float y);
	void SetRotate(float radians);
	void Rotate(float radians);
	void Translate(Vector3 v);
	void TranslateLocal(Vector3 v);
	void DistanceTo(GameObject obj);
	virtual void OnUpdate(float deltatime);
	virtual void OnDraw();
	void Update(float deltatime);
	void Draw();
};