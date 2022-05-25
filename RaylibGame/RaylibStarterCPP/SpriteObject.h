#pragma once
#include "GameObject.h"
#include <vector>
#include <string>
class SpriteObject : public GameObject {
public:
	SpriteObject();
	Texture2D* texture;
	vector<MyVector> corners;
	Color colour = WHITE;
	float Width; float Height;
	vector<MyVector> Corners();
	void Load(const char* filename);
	SpriteObject(const char* filename);
	virtual void OnDraw();
};