#include "Bullet.h"
#include "Game.h"
Bullet::Bullet(Game* owner, MyVector startpos) {
	game = owner;
	bulletSprite = SpriteObject("..\\Bullet.png");
	bulletSprite.SetPosition(-bulletSprite.Width / 2.0, -bulletSprite.Height / 2.0);
	game->rootObject.AddChild(this);
	TranslateLocal(startpos);
}
void Bullet::OnUpdate(float deltatime) {
	TranslateLocal(MyVector(0, 700 * deltatime, 0));
}