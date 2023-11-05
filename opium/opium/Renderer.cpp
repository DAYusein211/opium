#include "pch.hpp"

namespace opium
{
	Textures* textures = new Textures;
	InputHandler* input = new InputHandler;
	bool isUpdated = false;
	int index;
}
	
void Render::InitialiseTextures()
{
	opium::textures->InitialiseTextures();
}
void Render::Draw()
{
	for (int i = 0; i < 10; i++)
		if (CheckCollisionPointRec(GetMousePosition(), { opium::textures->flaskPositionX[i], opium::textures->flaskPositionY[i], 25, 50}))
			opium::index = i;

	opium::input->DragAndDrop(opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index],opium::textures->firstPosition[opium::index]);

	DrawTexture(opium::textures->room, 0, 0, WHITE);

	for (int i = 0; i < 2; i++)
		DrawTexture(opium::textures->flaskHolder, opium::textures->HolderPositionX[i], 600, WHITE);

	for (int i = 0; i < 10; i++)
		DrawTexture(opium::textures->flasks[i], opium::textures->flaskPositionX[i], opium::textures->flaskPositionY[i], WHITE);
	
	DrawTexture(opium::textures->shadows, 0, 0, WHITE);
}

void Render::UnloadTextures()
{
	delete opium::textures;
}