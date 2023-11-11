#include "pch.hpp"


Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
	SetTargetFPS(60);
};

namespace run
{
	bool isPlayOn = false, exit = false, isWindowClosed = false;
}

void Game::Run()
{
	Render* renderer = new Render;
	
	renderer->InitialiseTextures();

	while (!run::isWindowClosed)
	{
		BeginDrawing();

		if (!run::isPlayOn)
			renderer->MainMenu(run::isPlayOn, run::exit);
		else
			renderer->Draw();

		if (run::exit || WindowShouldClose())
			run::isWindowClosed = true;
		
		EndDrawing();
		
	}
	renderer->UnloadTextures();
}
Game::~Game()
{	
	CloseWindow();
}