#include "Bullet.h"
#include "Game.h"
Bullet::Bullet(Game* owner, Matrix3* startpos) {
	game = owner;
	bulletSprite = new SpriteObject("..\\Bullet.png");
	bulletSprite->SetPosition(-bulletSprite->Width / 2.0, -bulletSprite->Height / 2.0);
	this->AddChild(bulletSprite);
	game->rootObject.AddChild(this);
	*localTransform = *startpos;
}
void Bullet::Intersects(Collider other) {

}
void Bullet::OnUpdate(float deltatime) {
	TranslateLocal(MyVector(0, -700 * deltatime, 0));
}