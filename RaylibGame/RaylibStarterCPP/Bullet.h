#pragma once
#include "GameObject.h"
#include "SpriteObject.h"
class Game;
class Bullet : public GameObject {
public:
	Bullet(Game* owner, MyVector startpos);
	~Bullet();
	Game* game;
	void OnUpdate(float deltatime) override;
	void Intersects(Collider other);
private:
	SpriteObject bulletSprite;
};