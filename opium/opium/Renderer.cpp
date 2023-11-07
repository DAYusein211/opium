#include "pch.hpp"

namespace opium
{
	Textures* textures = new Textures;
	InputHandler* input = new InputHandler;
	Color flaskColor, bookColor;
	bool isUpdated = false, isEquipped = false, isBookOpened = false, isOnBowl = false;
	int index;
	int pageIndex = 0; 
	Color color[10] = { {255,0,0, 255}, {0,255,0, 255}, {0,0,255, 255}, {0,0,0, 255}, {0,0,0, 255}, {0,0,0, 255}, {0,0,0, 255}, {0,0,0, 255}, {0,0,0, 255}, {0,0,0, 255} }, bowlColor = RED;
	Vector2 center = { (GetScreenWidth() + 500) / 2.0f, (GetScreenHeight() + 400) / 2.0f };
}
	
void Render::InitialiseTextures()
{
	opium::textures->InitialiseTextures();
}
void Render::Draw()
{
	for (int i = 0; i < 10; i++)
		if (CheckCollisionPointRec(GetMousePosition(), { opium::textures->flaskPositionX[i], opium::textures->flaskPositionY[i], 25, 50 }) && !opium::isEquipped)
			opium::index = i;
	DrawTexture(opium::textures->room, 0, 0, WHITE);
	DrawRectangle(100, 100, 100, 100, BLUE);

	opium::input->DragAndDrop(opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index], opium::textures->firstPosition[opium::index], opium::isEquipped, opium::isOnBowl);
	if (opium::isOnBowl && CheckCollisionPointRec(GetMousePosition(), { 100, 100, 100, 100 }))
		opium::bowlColor = opium::color[opium::index];

	DrawCircleSector(opium::center, 180.0f, 270.0f, 450.0f, (int)20.0f, opium::bowlColor);



	for (int i = 0; i < 2; i++)
		DrawTexture(opium::textures->flaskHolder, opium::textures->HolderPositionX[i], 600, WHITE);

	for (int i = 0; i < 10; i++)
		DrawTexture(opium::textures->flasks[i], opium::textures->flaskPositionX[i], opium::textures->flaskPositionY[i], GRAY);
	
	opium::flaskColor = opium::input->getColor(opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index]);
	DrawTexture(opium::textures->flasks[opium::index], opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index], opium::flaskColor);

	opium::bookColor = opium::input->getColor(450, 685);
	DrawTexture(opium::textures->book, 450, 685, opium::bookColor);

	DrawTexture(opium::textures->shadows, 0, 0, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), { 450, 685, 100, 120 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		opium::isBookOpened = true;
	if (CheckCollisionPointRec(GetMousePosition(), { 600, 105, 40, 40 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		opium::isBookOpened = false;

	if (IsKeyPressed(KEY_W))
		opium::pageIndex--;
	if (IsKeyPressed(KEY_S))
		opium::pageIndex++;
	if (opium::pageIndex < 0)
		opium::pageIndex = 2; // gotta change this!!!!!!
	if (opium::pageIndex > 2) // this too
		opium::pageIndex = 0; 

	if (opium::isBookOpened)
		opium::textures->BookOpened(opium::pageIndex);
		
}

void Render::UnloadTextures()
{
	delete opium::textures;
}