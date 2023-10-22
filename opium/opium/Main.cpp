#include "pch.hpp"

int main()
{
	Game* game = new Game(1000, 1000, "dada");

	game->Run();

	delete game;
}