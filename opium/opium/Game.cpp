#include "pch.hpp"


Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
};



void Game::Run()
{

	Texture2D room = LoadTexture("../assets/noshadowroom.png");
	Texture2D shadows = LoadTexture("../assets/shadows.png");
	room.width = 1600;
	room.height = 900;
	shadows.width = 1600;
	shadows.height = 900;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawTexture(room, 0, 0, WHITE);
		DrawTexture(shadows, 0, 0, WHITE);
		EndDrawing();
	}

}
Game::~Game()
{	

	CloseWindow();
}