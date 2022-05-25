#include "Game.h"
#include "Player.h"
#include "raylib.h"
Game::Game(const char* bgFileName) {
	background = LoadImage(bgFileName);
}
void Game::Init() {
	SetTargetFPS(60);
	bgTexture = LoadTextureFromImage(background);
	score = 0;
	deltaTime = 0.005f;
	oldTime = 0;
	horbounds.push_back(Plane(MyVector(0, -1, 0), screenHeight));
	horbounds.push_back(Plane(MyVector(0, 1, 0), 0));
	verbounds.push_back(Plane(MyVector(-1, 0, 0), screenWidth));
	verbounds.push_back(Plane(MyVector(1, 0, 0), 0));
	Player* player = new Player(this);
}
void Game::ShutDown() {
}
void Game::Update() {
	deltaTime = (clock() - oldTime) / 1000.0f;
	oldTime = clock();
	rootObject.Update(deltaTime);
}
void Game::Draw() {
	BeginDrawing();
	DrawTexture(bgTexture, 0, 0, WHITE);
	rootObject.Draw();


	for (Plane p : horbounds) {
		p.DrawPlane();
	}
	for (Plane p : verbounds) {
		p.DrawPlane();
	}
	EndDrawing();
}
