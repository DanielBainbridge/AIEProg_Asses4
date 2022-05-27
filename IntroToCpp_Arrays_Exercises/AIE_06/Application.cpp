#include "Application.h"
#include "raylib.h"
#include <stdlib.h>


Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	//sets size of window, target frame rate and loads the initial application
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);

	Load();
	//while the window shouldn't close updates the window once a frame;
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void Application::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------
	//finds how many tiles to loop through and assigns an int value between 1 and 5 for colour
	int count = ROWS * COLS;
	for (int i = 0; i < count; i++)
	{
		m_tiles[i] = rand() % 5;
	}

	// -----------------------------------------------------
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	//when mouse button is pressed calculates the tile index based off of the mouse position then translates to 1d array then changes the colour value by 1
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		int rowIndex = mousePos.y / m_tileHeight; 
		int colIndex = mousePos.x / m_tileWidth;

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = (rowIndex * COLS) + colIndex;

		m_tiles[tileIndex] += 1;
		if (m_tiles[tileIndex] >= 5)
			m_tiles[tileIndex] = 0;
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
	
	//draw a rectangle at beginning each position at the array position multiplied by the tiles size
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			Color color = GetTileColor(m_tiles[(i * ROWS) + j]); // pass in the tilevalue
			float xPos = j * m_tileHeight;
			float yPos = i * m_tileWidth;
			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}
	}
	// --------------------------------------------------------------------
	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	//assigns a colour based off of a case by case int
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}