#include "pch.hpp"

namespace test
{
	Textures* textures = new Textures;
	Vector2 mouse;
	
}
void InputHandler::Update()
{
	test::mouse = GetMousePosition();
	for (int i = 0; i < 10; i++)
	{
		if (CheckCollisionPointRec(test::mouse, { 0, test::textures->flaskPositionY, 200, 100 }))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				test::textures->flaskPositionX[i] = test::mouse.x;
				test::textures->flaskPositionY = test::mouse.y;
			}
		}
	}
}

void InputHandler::DragAndDrop()
{

}
