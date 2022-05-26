#include "Player.h"
#include "Game.h"
#include "Bullet.h"
Player::Player(Game* owner) {
	game = owner;
	game->rootObject.AddChild(this);
	speed = 0.0f;
	rotation = 0.0f;
	mass = 2.0f;
	playerSprite =  new SpriteObject("..\\Player.png");
	playerSprite->SetPosition(-playerSprite->Width / 2.0f, -playerSprite->Height / 2.0f);
	collider->radius = playerSprite->Height / 2.0f;
	this->AddChild(playerSprite);
	this->SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
}
void Player::Intersects(Collider other) {

}
void Player::Teleport() {
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
void Player::OnUpdate(float deltatime) {
	if (IsKeyDown(KEY_W)){
		if (speed > maxspeed) {
			speed -= 10.0f;
		}
	}
	if (IsKeyUp(KEY_W))
	{
		if (speed < 0) {
			speed += mass;
		}
	}
	if (IsKeyDown(KEY_A)) {
		Rotate(-0.1f);
		if (rotation == 360){
			rotation = 0;
		}
	}
	if (IsKeyDown(KEY_D)) {
		Rotate(0.1f);
		if (rotation == 0){
			rotation = 360;
		}
	}
	if (IsKeyPressed(KEY_SPACE)) {
		new Bullet(this->game, this->localTransform);
		std::printf("a bullet has been fired dillweed");
	}
	this->TranslateLocal(MyVector(0, speed, 0) * deltatime);
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
	Teleport();
}
