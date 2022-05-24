#pragma once
#include "GameObject.h"
#include "SpriteObject.h"
class Game;
class Player : GameObject{
public:
	Player(Game* owner);
	Game* game;
	SpriteObject playerSprite;
	float speed;
	float maxspeed = 500.0f;
	float mass;
	float rotation;
	void Intersects(Collider other);
	void Player::OnUpdate(float deltatime);
};