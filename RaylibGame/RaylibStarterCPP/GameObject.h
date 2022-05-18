#pragma once
#include "raylib.h"
#include <vector>

using namespace std;

class GameObject {
public:
	vector<GameObject> children;
	vector<GameObject> childrenAddPending;
	vector<GameObject> childrenRemovePending;
protected:
	Matrix localTransform;
	Matrix globalTransform;
public:
	void AddChild();
	void RemoveChild();
	void RemoveFromParent();
	void CopyTransformToLocal();
	void UpdateTransform();
	void SetPosition();
	void SetRotate();
	void Rotate();
	void Translate();
	void TranslateLocal();
	void DistanceTo();
	void OnUpdate();
	void OnDraw();
	void Update();
	void Draw();
};