#include "pch.hpp"

namespace test
{
	Textures* texture = new Textures;
	Vector2 mouse;
	bool isDragActive = false;
}
void InputHandler::DragAndDrop(float& flaskPositionX, float& flaskPositionY, Vector2 firstPosition)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			test::isDragActive = true;

	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{

		test::isDragActive = false;

		flaskPositionX = firstPosition.x;
		flaskPositionY = firstPosition.y;
	}

	if (test::isDragActive)
	{
		flaskPositionX = GetMousePosition().x - 10;
		flaskPositionY = GetMousePosition().y - 30;
	}
}


