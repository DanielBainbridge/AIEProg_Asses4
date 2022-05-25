#pragma once
#include "GameObject.h"
class Game;
class Asteroid : GameObject{
	float speed = 500.0f;
	float rotation;
	int split;
	Game* game;
	Asteroid(Game* owner, float rotation, int split);
	~Asteroid();
	void Intersects(Collider other);
	void OnUpdate(float deltatime) override;
};