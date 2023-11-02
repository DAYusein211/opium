#include "pch.hpp"


Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
};



void Game::Run()
{

	Render room, shadows;
	room.texture = LoadTexture("../assets/noshadowroom.png");
	shadows.texture = LoadTexture("../assets/shadows.png");
	room.texture.width = 1600;
	room.texture.height = 900;
	shadows.texture.width = 1600;
	shadows.texture.height = 900;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		

		room.Draw();
		shadows.Draw();
		EndDrawing();
	}

}
Game::~Game()
{	

	CloseWindow();
}