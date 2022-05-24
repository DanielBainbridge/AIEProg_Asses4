#pragma once
#include "GameObject.h"
class Asteroid : GameObject{
	float speed = 500.0f;
	float rotation;
	int split;
	Asteroid(float rotation, int split);
	void Intersects(Collider other);
};