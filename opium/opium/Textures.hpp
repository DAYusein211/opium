#include "pch.hpp"
class Textures
{
public:
	
	Texture2D flaskHolder, book, room, shadows, bowl, playButton, cells, tryButton;
	std::vector<Texture2D> flasks, pages;
	float flaskPositionX[10];
	std::vector<float> HolderPositionX;

	float flaskPositionY[10];
	Vector2 firstPosition[10];
	//Returns flask file directory 
	std::string GetDirectory(int number, std::string object);

	//Sets texture size
	void SetSize(Texture2D& texture, int height, int width);

	//Initialises game textures
	void InitialiseTextures();

	//Renders guide book
	void BookOpened(int index);

	//Removes used flasks
	void RemoveFlask(int index);

	//Restores removed flasks
	void RestoreFlask(int index);

	//Destructor for unloading all textures
	~Textures();
	
};