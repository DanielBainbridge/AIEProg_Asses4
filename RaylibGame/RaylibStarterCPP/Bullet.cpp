#include "Bullet.h"
#include "Game.h"
Bullet::Bullet(Game* owner, Matrix3* startpos) {
	game = owner;
	bulletSprite = new SpriteObject("..\\Bullet.png");
	bulletSprite->SetPosition(-bulletSprite->Width / 2.0, -bulletSprite->Height / 2.0);
	collider->radius = bulletSprite->Width / 2.0f;
	this->AddChild(bulletSprite);
	game->rootObject.AddChild(this);
	*localTransform = *startpos;
	TranslateLocal(MyVector(0, 5, 0));
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
}
Bullet::~Bullet() {
	delete bulletSprite;
	delete collider;
}
void Bullet::Intersects(Collider* other) {
	Asteroid* ast = dynamic_cast<Asteroid*>(other);
	if (ast != nullptr) {
		if (collider->Intersects(ast->collider)) {
			if (ast->split == 0) {
				ast->game->score += 300;
				for (Asteroid* astpointer : ast->game->enemies) {
					if (astpointer == ast) {
						auto it = std::find(ast->game->enemies.begin(), ast->game->enemies.end(), ast);
						ast->game->enemies.erase(it);
					}
						
				}
				ast->RemoveFromParent();
				this->RemoveFromParent();
			}
			else {
				new Asteroid(ast->game, ast->split - 1, ast->GlobalTransformAsVector().x, ast->GlobalTransformAsVector().y, ast->rotation);
				new Asteroid(ast->game, ast->split - 1, ast->GlobalTransformAsVector().x, ast->GlobalTransformAsVector().y, ast->rotation);

				ast->game->score += 50;
				ast->split -= 1;
				this->RemoveFromParent();

			}
		}
	}


}
void Bullet::OutOfBounds() {
	for (Plane* p : game->verbounds) {
		if (p->TestSide(collider->origin) == Plane::BACK)
		{
			game->rootObject.RemoveChild(this);
			break;
		}
	}
	for (Plane* p : game->horbounds) {
		if (p->TestSide(collider->origin) == Plane::BACK)
		{
			game->rootObject.RemoveChild(this);
			break;
		}
	}
}
void Bullet::OnUpdate(float deltatime) {
	TranslateLocal(MyVector(0, -700 * deltatime, 0));
	collider->origin.x = localTransform->m20; collider->origin.y = localTransform->m21;
	OutOfBounds();
	for (GameObject* go : game->rootObject.children) {
		this->Intersects(go);
	}
	if (this->parent == nullptr)
	{
		printf("this object was removed");
	}
}