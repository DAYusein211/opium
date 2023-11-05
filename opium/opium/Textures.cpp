#include "pch.hpp"
void Textures::SetSize(Texture2D* texture, int height, int width)
{
	texture->height = height;
	texture->width = width;
}
std::string Textures::GetDirectory(int number)
{
	std::string dir = "../assets/flask" + std::to_string(number) + ".png";
	return dir;
}


void Textures::InitialiseTextures()
{
	float flaskPosX = 660, HolderPosX = 650;

	room = LoadTexture("../assets/room.png");
	shadows = LoadTexture("../assets/shadows.png");
	flaskHolder = LoadTexture("../assets/stoika.png");
	SetSize(&flaskHolder , 125, 225);

	SetSize(&room, 900, 1600);
	SetSize(&shadows, 900, 1600);

	for (int i = 0; i < 10; i++)
	{
		flask = LoadTexture(Textures::GetDirectory(i+1).c_str());
		flasks.push_back(flask);
		flaskPositionX[i] = flaskPosX;

		firstPosition[i] = { flaskPosX, 625 };

		if (i == 4)
			flaskPosX += 90;
		else
			flaskPosX += 42;

		flaskPositionY[i] = 625;
		
	}

	for (int i = 0; i < 2; i++)
	{
		HolderPositionX.push_back(HolderPosX);
		HolderPosX += 250;
	}
}

Textures::~Textures()
{
	UnloadTexture(room);
	UnloadTexture(shadows);
	UnloadTexture(flaskHolder);

	for (auto i = flasks.begin(); i != flasks.end(); i++)
		UnloadTexture(*i);

}