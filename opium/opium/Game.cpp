
#include "Game.hpp"

Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
	SetTargetFPS(60);
	isPlayOn = false;
	exit = false;
	isWindowClosed = false;
	fadeOutOver = false;
	fadeOut = { 0,0,0, 255 };
};



void Game::Run()
{
	Render* renderer = new Render();
	
	renderer->InitialiseTextures();

	while (!isWindowClosed)
	{
		BeginDrawing();

		if (!isPlayOn)
			renderer->MainMenu(isPlayOn, exit);
		else
		{

				renderer->Draw();
			renderer->FadeOut(fadeOut, fadeOutOver);
			
			
		}

		if (exit || WindowShouldClose())
			isWindowClosed = true;
		
		EndDrawing();
		
	}
	renderer->UnloadTextures();
}
Game::~Game()
{	
	CloseWindow();
}