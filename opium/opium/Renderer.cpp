#include "pch.hpp"

namespace opium
{
	Textures* textures = new Textures;
	InputHandler* input = new InputHandler;
	Color flaskColor, bookColor;
	bool isUpdated = false, isEquipped = false, isBookOpened = false, isOnBowl = false, isDragActive = false;
	int index, mixCount = 0;
	int pageIndex = 0; 
	Color color[10] = { {223, 255, 7, 255}, {228, 73, 179, 255}, {74, 139, 255, 255}, {86, 223, 13, 255}, {209, 16, 64, 255}, {44, 191, 147, 255}, {78, 66, 114, 255}, {191, 191, 191, 255}, {145, 214, 180, 255}, {228, 145, 89, 255} }, bowlColor = WHITE;
	Vector2 center = { 759, 806 };
}
	
void Render::MainMenu(bool& isPlayOn, bool& exit)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
	DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 200, 50, BLUE);
	DrawText("Play", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, WHITE);
	DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2 + 100, 200, 50, BLUE);
	DrawText("Exit", GetScreenWidth() / 2, GetScreenHeight() / 2 + 100, 20, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2, 200, 50, }))
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			isPlayOn = true;
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 + 100, 200, 50, }))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			exit = true;
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

	opium::input->DragAndDrop(opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index], opium::textures->firstPosition[opium::index], opium::isEquipped, opium::isOnBowl, opium::mixCount);
	
	if (CheckCollisionPointRec(GetMousePosition(), { opium:: textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index] , 25, 50}))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			opium::isDragActive = true;
		}
	}

	if (opium::isOnBowl && opium::isDragActive&& CheckCollisionPointRec(GetMousePosition(), { 660, 740, 200, 400 }) && opium::mixCount <= 2)
	{
		opium::bowlColor.r = 255 - (sqrt(pow((255 - (opium::bowlColor.r)), 2) + pow((255 - (opium::color[opium::index].r)), 2) / 2));
		opium::bowlColor.g = 255 - (sqrt(pow((255 - (opium::bowlColor.g)), 2) + pow((255 - (opium::color[opium::index].g)), 2) / 2));
		opium::bowlColor.b = 255 - (sqrt(pow((255 - (opium::bowlColor.b)), 2) + pow((255 - (opium::color[opium::index].b)), 2) / 2));
		opium::isDragActive = false;
	}

	DrawCircleSector(opium::center, 81.0f, 270.0f, 450.0f, (int)20.0f, opium::bowlColor);

	DrawTexture(opium::textures->bowl, 560, 700, WHITE);


	for (int i = 0; i < 2; i++)
		DrawTexture(opium::textures->flaskHolder, opium::textures->HolderPositionX[i], 600, WHITE);

	for (int i = 0; i < 10; i++)
		DrawTexture(opium::textures->flasks[i], opium::textures->flaskPositionX[i], opium::textures->flaskPositionY[i], GRAY);
	
	opium::flaskColor = opium::input->getColor(opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index]);
	DrawTexture(opium::textures->flasks[opium::index], opium::textures->flaskPositionX[opium::index], opium::textures->flaskPositionY[opium::index], opium::flaskColor);

	opium::bookColor = opium::input->getColor(450, 685);
	DrawTexture(opium::textures->book, 450, 685, opium::bookColor);

	DrawTexture(opium::textures->shadows, 0, 0, WHITE);

	DrawRectangle(100, 100, 100, 100, BLUE);
	if (CheckCollisionPointRec(GetMousePosition(), { 100, 100, 100, 100 }))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			opium::bowlColor = WHITE;
			opium::mixCount = 0;
		}
	}

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