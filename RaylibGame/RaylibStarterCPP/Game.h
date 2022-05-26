#pragma once
#include "GameObject.h"
#include <time.h>
#include "Asteroid.h"
#include "Player.h"
class Game {
public:
	Game(const char* bgFileName);
	GameObject rootObject;
	vector<Asteroid*> enemies;
	int score;
	int level = 1;
	float deltaTime;
	float oldTime;
	void Init();
	void ShutDown();
	void Update();
	void Draw();
	int screenWidth = 1920;
	int screenHeight = 1080;
	vector<Plane*> horbounds;
	vector<Plane*> verbounds;
	Player* player;
private:
	long currentTime;
	long lastTime;
	Image background;
	Texture2D bgTexture;
};
