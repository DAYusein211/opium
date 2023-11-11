class InputHandler
{
public:
	void DragAndDrop(float& flaskPositionX, float& flaskPositionY, Texture2D flask, Vector2 firstPosition, bool& isEquipped, bool& isOnBowl, int& mixCount, bool& isDropped);
	void Move(float& pointX, float& pointY, float& destinationX, float& destinationY, bool& isFinished);
	Color getColor(float posX, float posY);
};