#include "Asteroid.h"
#include "Game.h"
Asteroid::Asteroid(Game* owner, int split) {
	game = owner;
	this->split = split;
	if (split < 1) {
		rotation = rand() % 360;
	}
	else rotation += rand() % 30;
	this->Rotate(rotation);
	asteroidSprite = new SpriteObject("..\\Asteroid.png");
	asteroidSprite->SetPosition(-asteroidSprite->Width / 2.0, -asteroidSprite->Height / 2.0);	
	this->localTransform->SetTranslation(rand() % 1920, rand() % 1080);
	this->AddChild(asteroidSprite);
	game->rootObject.AddChild(this);
	game->enemies.push_back(this);
	collider->radius = asteroidSprite->Width / 2.0;
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
}
Asteroid::Asteroid(Game* owner, int split, int x, int y, float rotation) {
	game = owner;
	this->split = split;
	if (split < 1) {
		rotation = rand() % 360;
	}
	else rotation += rand() % 10;
	this->Rotate(rotation);
	asteroidSprite = new SpriteObject("..\\Asteroid.png");
	asteroidSprite->SetPosition(-asteroidSprite->Width / 2.0, -asteroidSprite->Height / 2.0);
	this->localTransform->SetTranslation(x, y);
	this->AddChild(asteroidSprite);
	game->enemies.push_back(this);
	game->rootObject.AddChild(this);
	collider->radius = asteroidSprite->Width / 2.0;
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
}
Asteroid::~Asteroid() {
	}
void Asteroid::Intersects(Collider* other) {
	
}
void Asteroid::Teleport() {
	for (Plane* p : game->verbounds) {
		if (p->TestSide(collider->origin) == Plane::BACK)
		{
			if (p->d == GetScreenWidth()) {
				this->SetPosition(0, this->globalTransform->m21);
			}
			else this->SetPosition(1920, this->globalTransform->m21);
		}
	}
	for (Plane* p : game->horbounds) {
		if (p->TestSide(collider->origin) == Plane::BACK)
		{
			if (p->d == GetScreenHeight()) {
				this->SetPosition(this->globalTransform->m20, 0);
			}
			else this->SetPosition(this->globalTransform->m20, 1080);
		}
	}
}
void Asteroid::OnUpdate(float deltatime) {
	TranslateLocal(MyVector(speed * deltatime, 0, 0));
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
	Teleport();
}