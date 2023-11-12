
#include "Textures.hpp"

void Textures::SetSize(Texture2D& texture, int height, int width)
{
	texture.height = height;
	texture.width = width;
}
std::string Textures::GetDirectory(int number, std::string object)
{
	
	std::string dir = "../assets/" + object + std::to_string(number) + ".png";
	return dir;
}


void Textures::InitialiseTextures()
{
	float flaskPosX = 660, HolderPosX = 650;
	Texture2D flask, page;
	room = LoadTexture("../assets/room.png");
	shadows = LoadTexture("../assets/shadows.png");
	flaskHolder = LoadTexture("../assets/stoika.png");
	book = LoadTexture("../assets/book.png");
	bowl = LoadTexture("../assets/bowl.png");
	playButton = LoadTexture("../assets/playButton.png");
	tryButton = LoadTexture("../assets/tryButton.png");
	cells = LoadTexture("../assets/cells/cellsAnimation.png");
	SetSize(flaskHolder , 125, 225);
	SetSize(book, 100, 120);
	SetSize(room, 900, 1600);
	SetSize(shadows, 900, 1600);
	SetSize(bowl, 200, 400);
	SetSize(cells, cells.height * 3, cells.width * 3);
	SetSize(playButton, playButton.height * 2, playButton.width * 2);
	SetSize(tryButton, tryButton.height * 2, tryButton.width * 2);
	for (int i = 0; i < 10; i++)
	{
		flask = LoadTexture(Textures::GetDirectory(i+1, "flask").c_str());
		page = LoadTexture(Textures::GetDirectory(i + 1, "page").c_str());
		flasks.push_back(flask);
		pages.push_back(page);

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

void Textures::BookOpened(int index)
{
	DrawTexture(pages[index], 100, 100, WHITE);
}

void Textures::RemoveFlask(int index)
{
	flasks[index].height = 0;
	flasks[index].width = 0;
}

void Textures::RestoreFlask(int index)
{
	flasks[index].height = 55;
	flasks[index].width = 19;
}

Textures::~Textures()
{
	UnloadTexture(room);
	UnloadTexture(shadows);
	UnloadTexture(flaskHolder);
	UnloadTexture(bowl);
	for (auto i = flasks.begin(); i != flasks.end(); i++)
		UnloadTexture(*i);

}