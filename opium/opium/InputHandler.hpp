#include "pch.hpp"
class InputHandler
{
public:

	
	//Handles drag and drop 
	void DragAndDrop(float& flaskPositionX, float& flaskPositionY, Texture2D flask, Vector2 firstPosition, bool& isEquipped, bool& isDropped);
	
	//Animation of flasks returning to their original place
	void Move(float& pointX, float& pointY, float& destinationX, float& destinationY, bool& isFinished);

	void InputHandlerMove(float& pointX, float& pointY, float& destinationX, float& destinationY, bool& isFinished);
	//Sets bowl's color to be as the flask's color
	Color getColor(float posX, float posY);
};