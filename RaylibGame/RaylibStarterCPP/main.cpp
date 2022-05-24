#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "Game.h"
using namespace Asteroids;

int main(int argc, char* argv[])
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    Game game = Game("..\\Background.png");
    InitWindow(1920, 1080, "Asteroids");
    ToggleFullscreen();
    game.Init();
    
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        game.Update();
        game.Draw();
    }
    game.ShutDown();

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}