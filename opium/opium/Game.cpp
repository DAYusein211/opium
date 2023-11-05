#include "pch.hpp"


Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
};



void Game::Run()
{
	Render* renderer = new Render;
	InputHandler* input = new InputHandler;

	renderer->InitialiseTextures();

	
	while (!WindowShouldClose())
	{
		input->Update();

		BeginDrawing();
		
		renderer->Draw();
		
		EndDrawing();
	}

}
Game::~Game()
{	

	CloseWindow();
}