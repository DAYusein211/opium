
#include "Renderer.hpp"
Render::Render()
{
	text = "";
	letterIndex = 0;
	delay = 0;
	frameTime = 0;
	stats = "Subject has contained cancer";
	textures = new Textures;
	input = new InputHandler;
	isPossible = false;
	switchTransition = false;
	isDropped = true;
	isWritten = true;
	isUpdated = false;
	isEquipped = false;
	isBookOpened = false;
	isOnBowl = false;
	mixCount = 0;
	switchFrame = 0;
	pageIndex = 0;
	reactionIndex = 0;
	chemicalCompounds = { "","","H2O","","","Cr(OH3)","","","","" };
	
	color.resize(10);
	color = { {223, 255, 7, 255}, {228, 73, 179, 255}, {74, 139, 255, 255}, {86, 223, 13, 255}, {209, 16, 64, 255}, {44, 191, 147, 255}, {78, 66, 114, 255}, {191, 191, 191, 255}, {145, 214, 180, 255}, {228, 145, 89, 255} };
	bowlColor = { 255, 255, 255, 0 };
	center = { 759, 806 };
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
	Rectangle buttonFrame;
	buttonFrame = { 0,0,(float)textures->playButton.width / 2, float(textures->playButton.height)};
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 - 100,(float)GetScreenHeight() / 2, 200, 100, }))
		buttonFrame.x = textures->playButton.width/2;

	DrawTexture(textures->room, 0, 0, WHITE);
	DrawTexture(textures->shadows, 0, 0, WHITE);
	DrawTextureRec(textures->playButton, buttonFrame, {(float)GetScreenWidth()/2 - 100,(float)GetScreenHeight()/2}, WHITE);
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
	textures->InitialiseTextures();
}

			
void Render::SubjectStats(std::string& stats)
{
	
	
	DrawRectangle(380, 110, 400, 100, BLACK);

	delay += GetFrameTime();
	
	if (delay > .1f && letterIndex < stats.size())
	{
		delay = 0.0f;
		text += stats[letterIndex];
		letterIndex++;

	}
	if (switchFrame == 9 && isWritten)
	{
		text = "";
		stats = "Subject has been healed";
		letterIndex = 0;
		isWritten = false;
	}
	std::cout << switchFrame << std::endl;
	DrawText(text.c_str(), 420, 130, 20, WHITE);
}

void Render::CellsUnderMicroscope(Texture2D cells)
{
	
	Rectangle currentFrame = { switchFrame * cells.width / 11,0, (float)cells.width / 11, (float)cells.height };
	DrawTextureRec(cells, currentFrame , {180, 110}, WHITE);
	
	frameTime += GetFrameTime();

	if (frameTime > 0.3f)
	{
		if (switchFrame < 11)
			switchFrame++;
		else
			switchFrame = 0;
		frameTime = 0;
	}
	
}

void Render::TryChemicalReaction(Texture2D button)
{
	Rectangle buttonFrame = { 0, 0, (float)button.width / 2, (float)button.height };
		if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth()/2 + 100, (float)GetScreenHeight() - 150, (float)button.width / 2, (float)button.height}))
			buttonFrame.x = button.width / 2;
		DrawTextureRec(button, buttonFrame, { (float)GetScreenWidth()/2 + 100, float(GetScreenHeight() - 150) }, WHITE);
}
void Render::Draw()
{
	for (int i = 0; i < 10; i++)
		if (CheckCollisionPointRec(GetMousePosition(), { textures->flaskPositionX[i], textures->flaskPositionY[i], 25, 50 }) && !isEquipped && isDropped)
			index = i;
	DrawTexture(textures->room, 0, 0, WHITE);
	input->DragAndDrop(textures->flaskPositionX[index], textures->flaskPositionY[index], textures->flasks[index], textures->firstPosition[index], isEquipped, isDropped);
	if (CheckCollisionPointRec(GetMousePosition(), { 100, 100, 100, 100 }))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			bowlColor = { 255, 255, 255, 0 };
			mixCount = 0;
			for (auto it = indexes.begin(); it != indexes.end(); it++)
				textures->RestoreFlask(*it);
			indexes.clear();
			chemicalReactions.clear();
			isPossible = 0;
			reactionIndex = 0;
		}
	}
	if (CheckCollisionPointRec({ textures->flaskPositionX[index], textures->flaskPositionY[index] }, { 660, 740, 200, 400 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < 5; i++)
		{
			bool flag = false;

			for (int j = 0; j < 2; j++)
			{
				
				if (possibleChemicalReactions[i][j].find(chemicalCompounds[index]))
				{

					chemicalReactions.push_back(chemicalCompounds[index]);
					flag = true;
					isPossible = true;
					isPreviousPossible = isPossible;
					break;
				}
			}
			if (flag)
				break;
		}
		
		
		
		if (isPossible)
		{
			mixCount++;
			isOnBowl = true;
		}
	}
	else
		isOnBowl = false;

	if (isOnBowl && mixCount <= 2)
	{

		//Sets bowl's color to be a mixture of 2 flasks colors'
		if (isPossible)
		{
			
			bowlColor.a = 255;
			bowlColor.r = 255 - (sqrt(pow((255 - (bowlColor.r)), 2) + pow((255 - (color[index].r)), 2) / 2));
			bowlColor.g = 255 - (sqrt(pow((255 - (bowlColor.g)), 2) + pow((255 - (color[index].g)), 2) / 2));
			bowlColor.b = 255 - (sqrt(pow((255 - (bowlColor.b)), 2) + pow((255 - (color[index].b)), 2) / 2));
			indexes.push_back(index);
			textures->RemoveFlask(index);
			isPossible = true;
		}
		
	}

	
	DrawCircleSector(center, 81.0f, 270.0f, 450.0f, (int)20.0f, bowlColor);

	DrawTexture(textures->bowl, 560, 700, WHITE);


	for (int i = 0; i < 2; i++)
		DrawTexture(textures->flaskHolder, textures->HolderPositionX[i], 600, WHITE);

	for (int i = 0; i < 10; i++)
		DrawTexture(textures->flasks[i], textures->flaskPositionX[i], textures->flaskPositionY[i], GRAY);
	
	flaskColor = input->getColor(textures->flaskPositionX[index], textures->flaskPositionY[index]);
	DrawTexture(textures->flasks[index], textures->flaskPositionX[index], textures->flaskPositionY[index], flaskColor);

	bookColor = input->getColor(450, 685);
	DrawTexture(textures->book, 450, 685, bookColor);


	DrawTexture(textures->shadows, 0, 0, WHITE);
	SubjectStats(stats);
	CellsUnderMicroscope(textures->cells);
	
	
	
	TryChemicalReaction(textures->tryButton);
	DrawRectangle(100, 100, 100, 100, BLUE);
	

	if (CheckCollisionPointRec(GetMousePosition(), { 450, 685, 100, 120 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		isBookOpened = true;
	if (CheckCollisionPointRec(GetMousePosition(), { 600, 105, 40, 40 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		isBookOpened = false;

	if (IsKeyPressed(KEY_W))
		pageIndex--;
	if (IsKeyPressed(KEY_S))
		pageIndex++;
	if (pageIndex < 0)
		pageIndex = 2; // gotta change this!!!!!!
	if (pageIndex > 2) // this too
		pageIndex = 0; 

	if (isBookOpened)
		textures->BookOpened(pageIndex);
		
}

void Render::UnloadTextures()
{
	delete textures;
}