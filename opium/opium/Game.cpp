#include "pch.hpp"


Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
};



void Game::Run()
{
	Render* renderer = new Render;

	renderer->InitialiseTextures();

	
	while (!WindowShouldClose())
	{
		

		BeginDrawing();

		renderer->Draw();
		EndDrawing();
	}

}
Game::~Game()
{	

	CloseWindow();
}