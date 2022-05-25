#include "SpriteObject.h"
SpriteObject::SpriteObject(){
}
vector<MyVector*> SpriteObject::Corners() {
	corners.clear();
	corners.push_back(new MyVector(this->GlobalTransformAsVector() + *parent->GlobalTransformAsVector()));
	corners.push_back(new MyVector(this->GlobalTransformAsVector() + MyVector(Width, 0, 0) + *parent->GlobalTransformAsVector()));
	corners.push_back(new MyVector(this->GlobalTransformAsVector() + MyVector(0, Height, 0) + *parent->GlobalTransformAsVector()));
	corners.push_back(new MyVector(this->GlobalTransformAsVector() + MyVector(Width, Height, 0) + *parent->GlobalTransformAsVector()));
	return corners;
}
void SpriteObject::Load(const char* filename) {
	Image img = LoadImage(filename);
	texture = new Texture2D(LoadTextureFromImage(img));
}
SpriteObject::SpriteObject(const char* filename) {
	Load(filename);
	Height = texture->height;
	Width = texture->width;
}
void SpriteObject::OnDraw() {
	float rotation = (float)atan2(globalTransform->m01, globalTransform->m00) * (float)(180 / PI);
	DrawTextureEx(*texture, Vector2{ globalTransform->m20, globalTransform->m21 }, rotation, 1, colour);
}
