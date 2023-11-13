
#include "Textures.hpp"

void Textures::SetSize(Texture2D& texture, int height, int width)
{
	texture.height = height;
	texture.width = width;
}
std::string Textures::GetDirectory(int number, std::string object)
{
	
	std::string dir = "../assets/flasks/" + object + std::to_string(number) + ".png";
	return dir;
}


void Textures::InitialiseTextures()
{
	float flaskPosX = 660, HolderPosX = 650;
	Texture2D flask;
	room = LoadTexture("../assets/room.png");
	pages = LoadTexture("../assets/bookPages.png");
	shadows = LoadTexture("../assets/shadows.png");
	flaskHolder = LoadTexture("../assets/stoika.png");
	book = LoadTexture("../assets/book.png");
	bowl = LoadTexture("../assets/bowl.png");
	playButton = LoadTexture("../assets/buttons/playButton.png");
	tryButton = LoadTexture("../assets/buttons/tryButton.png");
	resetButton = LoadTexture("../assets/buttons/resetButton.png");
	exitButton = LoadTexture("../assets/buttons/exitButton.png");
	cells = LoadTexture("../assets/cells/cellsAnimation.png");
	toxicCells = LoadTexture("../assets/cells/toxicCells.png");
	subjectIdle = LoadTexture("../assets/subjectAnimations/idleAnimation.png");
	glass = LoadTexture("../assets/glass.png");
	subjectCancer = LoadTexture("../assets/subjectAnimations/cancerAnimation.png");
	cancerCells = LoadTexture("../assets/cells/cancerCells.png");
	subjectToxic = LoadTexture("../assets/subjectAnimations/meltingAnimation.png");
	subjectBurn = LoadTexture("../assets/subjectAnimations/burningAnimation.png");
	closeX = LoadTexture("../assets/buttons/closeBook.png");
	SetSize(glass, 900, 1600);
	SetSize(flaskHolder , 125, 225);
	SetSize(book, 100, 120);
	SetSize(room, 900, 1600);
	SetSize(shadows, 900, 1600);
	SetSize(bowl, 200, 400);
	SetSize(closeX, 25, 25);
	SetSize(cells, cells.height * 3, cells.width * 3);
	SetSize(toxicCells, toxicCells.height * 3, toxicCells.width * 3);
	SetSize(cancerCells, cancerCells.height * 3, cancerCells.width * 3);

	SetSize(playButton, playButton.height * 2, playButton.width * 2);
	SetSize(tryButton, tryButton.height * 2, tryButton.width * 2);
	SetSize(resetButton, resetButton.height * 2, resetButton.width * 2);
	SetSize(exitButton, exitButton.height * 2, exitButton.width * 2);

	SetSize(subjectIdle, subjectIdle.height * 4, subjectIdle.width * 4);
	SetSize(subjectCancer, subjectCancer.height * 4, subjectCancer.width * 4);
	SetSize(subjectToxic, subjectToxic.height * 4, subjectToxic.width * 4);
	SetSize(subjectBurn, subjectBurn.height * 4, subjectBurn.width * 4);

	for (int i = 0; i < 10; i++)
	{
		flask = LoadTexture(Textures::GetDirectory(i + 1, "flask").c_str());
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
	UnloadTexture(playButton);
	UnloadTexture(tryButton);
	UnloadTexture(subjectIdle);
	UnloadTexture(cells);
	for (auto i = flasks.begin(); i != flasks.end(); i++)
		UnloadTexture(*i);

}