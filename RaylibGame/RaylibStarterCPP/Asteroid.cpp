#include "Asteroid.h"
#include "Game.h"
Asteroid::Asteroid(Game* owner, float rotation, int split) {
	game = owner;
	this->split = split;
	rotation += rand() % 30;
	this->SetRotate(rotation);
	asteroidSprite = new SpriteObject("..\\Asteroid.png");
	asteroidSprite->SetPosition(-asteroidSprite->Width / 2.0, -asteroidSprite->Height / 2.0);	
	collider->Fit(asteroidSprite->Corners());
	this->AddChild(asteroidSprite);
	game->rootObject.AddChild(this);
	this->localTransform->SetTranslation(rand() % 1920, rand() % 1080);
}
void Asteroid::Intersects(Collider other) {

}
void Asteroid::OnUpdate(float deltatime) {
	TranslateLocal(MyVector(speed * deltatime, 0, 0));
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
}