
#include "Game.hpp"
int main()
{
	Game* game = new Game(1600, 900, "dada");

	game->Run();

	delete game;
}