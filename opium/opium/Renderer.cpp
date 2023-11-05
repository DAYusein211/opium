#include "pch.hpp"
namespace opium
{
	Textures* textures = new Textures;
}
void Render::InitialiseTextures()
{
	opium::textures->InitialiseTextures();
}
void Render::Draw()
{
	DrawTexture(opium::textures->room, 0, 0, WHITE);

	for (int i = 0; i < 2; i++)
		DrawTexture(opium::textures->flaskHolder, opium::textures->HolderPositionX[i], 600, WHITE);

	for (int i = 0; i < 10; i++)
		DrawTexture(opium::textures->flasks[i], opium::textures->flaskPositionX[i], opium::textures->flaskPositionY, WHITE);
	
	DrawTexture(opium::textures->shadows, 0, 0, WHITE);
}

void Render::UnloadTextures()
{
	delete opium::textures;
}