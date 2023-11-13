
#include "InputHandler.hpp"

namespace userActions
{
	bool isDragActive = false, drop = false;
	Vector2 currentPos;
}
void InputHandler::Move(float& pointX, float& pointY, float& destinationX, float& destinationY, bool& isFinished)
{

	userActions::currentPos = {destinationX - pointX, destinationY - pointY };

	pointX += userActions::currentPos.x * 0.2;
	pointY += userActions::currentPos.y * 0.2;
	
	if (round(pointX) == destinationX && round(pointY) == destinationY)
	{
		userActions::drop = false;
		isFinished = true;
	}
	std::cout << pointX << ", " << pointY << " -> " << destinationX << ", " << destinationY << std::endl;
	
}

void InputHandler::DragAndDrop(float& flaskPositionX, float& flaskPositionY,Texture2D flask, Vector2 firstPosition, bool& isEquipped, bool& isDropped)
{
	
	if (userActions::drop)
		Move(flaskPositionX, flaskPositionY, firstPosition.x, firstPosition.y, isDropped);
	if (CheckCollisionPointRec(GetMousePosition(), { flaskPositionX, flaskPositionY, (float)flask.width, (float)flask.height }) && !isEquipped)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			userActions::isDragActive = true;
			isEquipped = true;
			isDropped = false;
		}
		
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) )
	{
		userActions::isDragActive = false;
		if(CheckCollisionPointRec(GetMousePosition(), { flaskPositionX - 50, flaskPositionY - 50, 100, 100 }))
			userActions::drop = true;
		isEquipped = false;
	}
	
	

	if (userActions::isDragActive)
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


