#include "Asteroid.h"

Asteroid::Asteroid(float rotation, int split) {
	this->split = split;
	this->SetRotate(rotation);
}
void Asteroid::Intersects(Collider other) {

}