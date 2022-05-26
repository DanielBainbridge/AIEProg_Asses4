#pragma once
#include "GameObject.h"
#include "SpriteObject.h"
class Game;
class Player : public GameObject{
public:
	Player(Game* owner);
	Game* game;
	SpriteObject* playerSprite;
	Sphere* collider = new Sphere();
	int lives = 3;
	bool alive = true;
	float timer = 5.0f;
	float speed;
	float maxspeed = -500.0f;
	float mass;
	float rotation;
	void Intersects(Collider* other);
	void Teleport();
	void OnUpdate(float deltatime) override;
};