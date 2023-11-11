#include "pch.hpp"

namespace core
{
	std::string text = "";
	int letterIndex = 0;
	float delay = 0;
	char stats[100] = "Subject has contained cancer";
	std::vector<int>indexes;
	Textures* textures = new Textures;
	InputHandler* input = new InputHandler;
	Color flaskColor, bookColor, fade;
	Rectangle buttonFrame;
	bool  switchTransition = false, isDropped = true, isUpdated = false, isEquipped = false, isBookOpened = false, isOnBowl = false;
	int index, mixCount = 0;
	int pageIndex = 0; 
	Color color[10] = { {223, 255, 7, 255}, {228, 73, 179, 255}, {74, 139, 255, 255}, {86, 223, 13, 255}, {209, 16, 64, 255}, {44, 191, 147, 255}, {78, 66, 114, 255}, {191, 191, 191, 255}, {145, 214, 180, 255}, {228, 145, 89, 255} }, bowlColor = { 255, 255, 255, 0 };
	Vector2 center = { 759, 806 };
	
}

void Render::FadeOut(Color& fadeOut, bool& isOver)
{
	if (fadeOut.a >= 4)
		fadeOut.a -= 4;
	
	if (fadeOut.a == 0)
		isOver = true;

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), fadeOut);

}


void Render::MainMenu(bool& isPlayOn, bool& exit)
{
	core::buttonFrame = { 0,0,(float)core::textures->playButton.width / 2, 50 };
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 - 100,(float)GetScreenHeight() / 2, 100, 50, }))
		core::buttonFrame.x = 100;

	DrawTexture(core::textures->room, 0, 0, WHITE);
	DrawTexture(core::textures->shadows, 0, 0, WHITE);
	DrawTextureRec(core::textures->playButton, core::buttonFrame, {(float)GetScreenWidth()/2 - 100,(float)GetScreenHeight()/2}, WHITE);
	DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2 + 100, 200, 50, BLUE);
	DrawText("Exit", GetScreenWidth() / 2, GetScreenHeight() / 2 + 100, 20, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 - 100,(float)GetScreenHeight() / 2, 300, 100, }))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			isPlayOn = true;


	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 + 100, 200, 50, }))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			exit = true;
}

void Render::InitialiseTextures()
{
	core::textures->InitialiseTextures();
}

			
void Render::SubjectStats(std::string stats)
{
	
	
	DrawRectangle(200, 200, 400, 100, BLACK);

	core::delay += GetFrameTime();
	
	if (core::delay > .1f && core::letterIndex < stats.size())
	{
		core::delay = 0.0f;
		core::text += stats[core::letterIndex];
		core::letterIndex++;

	}
	DrawText(core::text.c_str(), 220, 220, 20, WHITE);
}
void Render::Draw()
{
	for (int i = 0; i < 10; i++)
		if (CheckCollisionPointRec(GetMousePosition(), { core::textures->flaskPositionX[i], core::textures->flaskPositionY[i], 25, 50 }) && !core::isEquipped && core::isDropped)
			core::index = i;
	DrawTexture(core::textures->room, 0, 0, WHITE);
	if (core::isOnBowl && core::mixCount <= 2)
	{
		//Sets bowl's color to be a mixture of 2 flasks colors'

		core::bowlColor.a = 255;
		core::bowlColor.r = 255 - (sqrt(pow((255 - (core::bowlColor.r)), 2) + pow((255 - (core::color[core::index].r)), 2) / 2));
		core::bowlColor.g = 255 - (sqrt(pow((255 - (core::bowlColor.g)), 2) + pow((255 - (core::color[core::index].g)), 2) / 2));
		core::bowlColor.b = 255 - (sqrt(pow((255 - (core::bowlColor.b)), 2) + pow((255 - (core::color[core::index].b)), 2) / 2));
		core::indexes.push_back(core::index);
		core::textures->RemoveFlask(core::index);

	}
	if (CheckCollisionPointRec(GetMousePosition(), { 100, 100, 100, 100 }))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			core::bowlColor = { 255, 255, 255, 0 };
			core::mixCount = 0;
			for (auto it = core::indexes.begin(); it != core::indexes.end(); it++)
				core::textures->RestoreFlask(*it);
			core::indexes.clear();
		}
	}
	core::input->DragAndDrop(core::textures->flaskPositionX[core::index], core::textures->flaskPositionY[core::index], core::textures->flasks[core::index], core::textures->firstPosition[core::index], core::isEquipped, core::isOnBowl, core::mixCount, core::isDropped);

	DrawCircleSector(core::center, 81.0f, 270.0f, 450.0f, (int)20.0f, core::bowlColor);

	DrawTexture(core::textures->bowl, 560, 700, WHITE);


	for (int i = 0; i < 2; i++)
		DrawTexture(core::textures->flaskHolder, core::textures->HolderPositionX[i], 600, WHITE);

	for (int i = 0; i < 10; i++)
		DrawTexture(core::textures->flasks[i], core::textures->flaskPositionX[i], core::textures->flaskPositionY[i], GRAY);
	
	core::flaskColor = core::input->getColor(core::textures->flaskPositionX[core::index], core::textures->flaskPositionY[core::index]);
	DrawTexture(core::textures->flasks[core::index], core::textures->flaskPositionX[core::index], core::textures->flaskPositionY[core::index], core::flaskColor);

	core::bookColor = core::input->getColor(450, 685);
	DrawTexture(core::textures->book, 450, 685, core::bookColor);

	DrawTexture(core::textures->shadows, 0, 0, WHITE);
	SubjectStats(core::stats);
	DrawRectangle(100, 100, 100, 100, BLUE);
	

	if (CheckCollisionPointRec(GetMousePosition(), { 450, 685, 100, 120 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		core::isBookOpened = true;
	if (CheckCollisionPointRec(GetMousePosition(), { 600, 105, 40, 40 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		core::isBookOpened = false;

	if (IsKeyPressed(KEY_W))
		core::pageIndex--;
	if (IsKeyPressed(KEY_S))
		core::pageIndex++;
	if (core::pageIndex < 0)
		core::pageIndex = 2; // gotta change this!!!!!!
	if (core::pageIndex > 2) // this too
		core::pageIndex = 0; 

	if (core::isBookOpened)
		core::textures->BookOpened(core::pageIndex);
		
}

void Render::UnloadTextures()
{
	delete core::textures;
}