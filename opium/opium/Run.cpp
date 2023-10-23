#include "pch.hpp"

namespace Init
{
	UI* ui = new UI;
}
Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);

};

void Game::Run()
{
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		Init::ui->Render();
		EndDrawing();
	}

}



Game::~Game()
{
	delete Init::ui;
	CloseWindow();
}