#include "Player.h"
#include "Game.h"
Player::Player(Game* owner) {
	game = owner;
	speed = 0.0f;
	rotation = 0.0f;
	mass = 10.0f;
}
void Player::OnUpdate(float deltatime) {
	if (IsKeyDown(KEY_W)){
		if (speed < maxspeed) {
			speed += 10.0f;
		}
	}
	if (IsKeyDown(KEY_A)) {
		rotation += 1.0f;
		if (rotation == 360){
			rotation = 0;
		}
	}
	if (IsKeyDown(KEY_D)) {
		rotation -= 1.0f;
		if (rotation == 0){
			rotation = 360;
		}
	}
	this->Rotate(rotation);
	this->TranslateLocal(MyVector(0, speed, 0));
}
