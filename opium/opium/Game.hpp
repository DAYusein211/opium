#include "pch.hpp"
#include "Renderer.hpp"

class Game
{
private:
	bool isPlayOn, exit, isWindowClosed, fadeOutOver;
	Color fadeOut;
public:
	Game(int width, int height, const char* title);
	void Run();
	~Game();

};

