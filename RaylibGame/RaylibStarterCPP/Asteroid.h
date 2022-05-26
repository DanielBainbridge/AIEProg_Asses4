#pragma once
#include "GameObject.h"
#include "SpriteObject.h"
class Game;
class Asteroid : public GameObject{
public:
	int split;
	Game* game;
	Asteroid(Game* owner, int split);
	Asteroid(Game* owner, int split, int x, int y, float rotation);
	~Asteroid();
	void Intersects(Collider* other);
	void Teleport();
	void OnUpdate(float deltatime) override;
	Sphere* collider = new Sphere();
	float rotation;
private:
	SpriteObject* asteroidSprite;
	float speed = 250.0f;
};