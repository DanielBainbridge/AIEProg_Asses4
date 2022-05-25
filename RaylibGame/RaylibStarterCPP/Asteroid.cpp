#include "Asteroid.h"
#include "Game.h"
Asteroid::Asteroid(Game* owner, float rotation, int split) {
	this->split = split;
	this->SetRotate(rotation);
}
void Asteroid::Intersects(Collider other) {

}
void Asteroid::OnUpdate(float deltatime) {

}