#include "Game.h"
#include "Player.h"
#include "raylib.h"
#include "Player.h"
#include <cstring>
Game::Game(const char* bgFileName) {
	background = LoadImage(bgFileName);
}
void Game::Init() {
	SetTargetFPS(60);
	bgTexture = LoadTextureFromImage(background);
	score = 0;
	deltaTime = 0.005f;
	oldTime = 0;
	player = new Player(this);
	horbounds.push_back(new Plane(MyVector(0, -1, 0), screenHeight));
	horbounds.push_back(new Plane(MyVector(0, 1, 0), 0));
	verbounds.push_back(new Plane(MyVector(-1, 0, 0), screenWidth));
	verbounds.push_back(new Plane(MyVector(1, 0, 0), 0));
	
}
void Game::ShutDown() {
}
void Game::Update() {
	if (enemies.empty())
	{
		level++;
		for (size_t i = 0; i < level; i++)
		{
			Asteroid* asteroid = new Asteroid(this, 1);
		}
	}
	deltaTime = (clock() - oldTime) / 1000.0f;
	oldTime = clock();
	rootObject.Update(deltaTime);
}
void Game::Draw() {
	BeginDrawing();
	DrawTexture(bgTexture, 0, 0, WHITE);
	DrawText("Score:", 5, 20, 45, WHITE);
	DrawText("Lives:", 1750, 20, 45, WHITE);
	std::string tmpsc = std::to_string(score);
	const char* sch = tmpsc.c_str();
	std::string tmpli = std::to_string(player->lives);
	const char* plive = tmpli .c_str();
	DrawText(sch, 160, 20, 45, WHITE);
	if (player->alive == false) {
		DrawText("Game Over!", 750, 500, 65, RED);
		DrawText("0", 1885, 20, 45, WHITE);
	}
	else	DrawText(plive, 1885, 20, 45, WHITE);
	rootObject.Draw();
	EndDrawing();
}
