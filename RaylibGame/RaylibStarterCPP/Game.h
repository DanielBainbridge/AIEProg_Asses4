#pragma once
#include "GameObject.h"
#include <time.h>
namespace Asteroids {
	class Game {
	public:
		Game(const char* bgFileName);
		GameObject rootObject;
		int score;
		float deltaTime;
		float oldTime;
		void Init();
		void ShutDown();
		void Update();
		void Draw();
		int screenWidth = 1920;
		int screenHeight = 1080;
		vector<Plane> horbounds;
		vector<Plane> verbounds;
	private:
		long currentTime;
		long lastTime;
		Image background;
		Texture2D bgTexture;
	};
}