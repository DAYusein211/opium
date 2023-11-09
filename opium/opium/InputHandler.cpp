#include "pch.hpp"

namespace test
{
	Textures* texture = new Textures;
	Vector2 mouse;
	bool isDragActive = false;
}
void InputHandler::DragAndDrop(float& flaskPositionX, float& flaskPositionY, Vector2 firstPosition,bool &isEquipped, bool &isOnBowl, int& mixCount)
{
	if (CheckCollisionPointRec(GetMousePosition(), { flaskPositionX, flaskPositionY, 25, 50 }) && !isEquipped)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			test::isDragActive = true;
			isEquipped = true;
		}
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		

		test::isDragActive = false;

		flaskPositionX = firstPosition.x;
		flaskPositionY = firstPosition.y;
		isEquipped = false;
	}
	if (CheckCollisionPointRec(GetMousePosition(), { 660, 740, 200, 400 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		isOnBowl = true;
		mixCount++;
	}
	else
		isOnBowl = false;
	if (test::isDragActive)
	{
		flaskPositionX = GetMousePosition().x - 10;
		flaskPositionY = GetMousePosition().y - 30;
	}
}

Color InputHandler::getColor(float posX, float posY)
{
	Color color = GRAY;
	if (CheckCollisionPointRec(GetMousePosition(), { posX, posY, 100, 120 }))
		color = WHITE;
	else
		color = GRAY;
	return color;
}


