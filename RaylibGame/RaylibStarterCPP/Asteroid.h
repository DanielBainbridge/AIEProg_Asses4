#pragma once
#include "GameObject.h"
#include "SpriteObject.h"
class Game;
class Asteroid : public GameObject{
public:
	int split;
	Game* game;
	Asteroid(Game* owner, float rotation, int split);
	~Asteroid();
	void Intersects(Collider other);
	void OnUpdate(float deltatime) override;
	AABB* collider = new AABB();
private:
	SpriteObject* asteroidSprite;
	float speed = 250.0f;
	float rotation;
};