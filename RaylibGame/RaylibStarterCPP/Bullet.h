#pragma once
#include "GameObject.h"
#include "SpriteObject.h"
class Game;
class Bullet : public GameObject {
public:
	Bullet(Game* owner, Matrix3* startpos);
	~Bullet();
	Game* game;
	Sphere* collider = new Sphere();
	void OnUpdate(float deltatime) override;
	void Intersects(Collider* other);
	void OutOfBounds();
	
private:
	SpriteObject* bulletSprite;
};