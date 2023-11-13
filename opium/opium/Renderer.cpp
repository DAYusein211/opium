
#include "Renderer.hpp"
Render::Render()
{
	textures = new Textures;
	input = new InputHandler;
	isCleared = false;
	clearText = false;
	switchTransition = false;
	isDropped = true;
	isUpdated = false;
	isEquipped = false;
	isBookOpened = false;
	isOnBowl = false;
	tryOn = false;
	cancer = false;
	idle = false;
	toxic = false;
	burn = false;
	letterIndex = 0;
	delay = 0;
	frameTime = 0;
	subjectFrameTime = 0;
	mixCount = 0;
	cellFrame = 0;
	subjectFrame = 0;
	pageIndex = 0;
	reactionIndex = 0;
	color.resize(10);
	color = { {228, 219, 20, 255}, {64, 64, 61, 255}, {74, 139, 255, 144}, {86, 223, 13, 255}, {218, 223, 181, 255}, {44, 191, 147, 255}, {255, 221, 200, 255}, {191, 191, 191, 255}, {185, 255, 109, 255}, {255, 209, 214, 255} };
	bowlColor = { 255, 255, 255, 0 };
	center = { 759, 806 };

	chemicalCompounds = { "S","Fe","H2O","U","P","Cr(OH)3","Na","Ca","K","Mg" };
	stats = "-Subject is ready for experimental tests \n-White cells are healthy";
	text = "";

	
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
	Rectangle playButtonFrame, exitButtonFrame;
	playButtonFrame = { 0, 0,(float)textures->playButton.width / 2, (float)textures->playButton.height};
	exitButtonFrame = { 0, 0,(float)textures->exitButton.width / 2, (float)textures->exitButton.height };
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 - 400,(float)GetScreenHeight() / 2 - 100, 200, 100, }))
	{
		playButtonFrame.x = textures->playButton.width / 2;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			isPlayOn = true;
	}
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 + 150,(float)GetScreenHeight() / 2 - 100, 200, 100, }))
	{
		exitButtonFrame.x = textures->exitButton.width / 2;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			exit = true;
	}
	DrawTexture(textures->room, 0, 0, WHITE);

	DrawTexture(textures->shadows, 0, 0, WHITE);

	DrawTextureRec(textures->playButton, playButtonFrame, {(float)GetScreenWidth()/2 - 400,(float)GetScreenHeight()/2 - 100}, WHITE);
	DrawTextureRec(textures->exitButton, exitButtonFrame, {(float)GetScreenWidth() / 2 + 150, (float)GetScreenHeight() / 2 - 100 }, WHITE);

}

void Render::InitialiseTextures()
{
	textures->InitialiseTextures();
}

			
void Render::SubjectStats(std::string& stats)
{

	DrawRectangleRounded({ 360, 110, 630, 100, }, 0.2f, 0, {157, 144, 127, 255});
	DrawRectangleRoundedLines({ 360, 110, 630, 100, }, 0.2f, 0, 5, { 76, 39, 39, 255 });
	delay += GetFrameTime();
	
	if (delay > 0.1f && letterIndex < stats.size())
	{
		delay = 0.0f;
		text += stats[letterIndex];
		letterIndex++;
	}
	
	DrawText(text.c_str(), 440, 130, 20, { 76, 39, 39, 255 });
}

void Render::CellsUnderMicroscope(Texture2D cells, bool isNormal)
{
	frameTime += GetFrameTime();
	Rectangle currentFrame = { cellFrame * cells.width / 11, 0, (float)cells.width / 11, (float)cells.height };
	DrawTextureRec(cells, currentFrame , {180, 110}, WHITE);
	
	if (frameTime > 0.3f)
	{
		if (cellFrame < 10)
			cellFrame++;
		else if(isNormal)
			cellFrame = 0;
		frameTime = 0;
	}
	
}
void Render::SubjectIdle(Texture2D subject, int frames)
{
	subjectFrameTime += GetFrameTime();
	Rectangle currentFrame = { subjectFrame * subject.width / frames, 0, (float)subject.width / frames, (float)subject.height };
	DrawTextureRec(subject, currentFrame, { (float)GetScreenWidth()/2 - 100, 200}, WHITE);

	if (subjectFrameTime > 0.3f)
	{
		if (subjectFrame < frames)
			subjectFrame++;

		else 
			subjectFrame = 0;

		subjectFrameTime = 0;
	}
}
void Render::SubjectCancer(Texture2D subject, int frames)
{
	subjectFrameTime += GetFrameTime();
	Rectangle currentFrame = { subjectFrame * subject.width / frames, 0, (float)subject.width / frames, (float)subject.height };
	DrawTextureRec(subject, currentFrame, { (float)GetScreenWidth() / 2 - 200, 200 }, WHITE);

	if (subjectFrameTime > 0.3f)
	{
		if (subjectFrame < frames - 1)
			subjectFrame++;

		subjectFrameTime = 0;
	}
}
void Render::SubjectToxic(Texture2D subject, int frames)
{
	subjectFrameTime += GetFrameTime();
	Rectangle currentFrame = { subjectFrame * subject.width / frames, 0, (float)subject.width / frames, (float)subject.height };
	DrawTextureRec(subject, currentFrame, { (float)GetScreenWidth() / 2 - 240, 200 }, WHITE);

	if (subjectFrameTime > 0.1f)
	{
		if (subjectFrame < frames - 1)
			subjectFrame++;

		subjectFrameTime = 0;
	}
}
void Render::SubjectBurn(Texture2D subject, int frames)
{
	subjectFrameTime += GetFrameTime();
	Rectangle currentFrame = { subjectFrame * subject.width / frames, 0, (float)subject.width / frames, (float)subject.height };
	DrawTextureRec(subject, currentFrame, { (float)GetScreenWidth() / 2 - 80, 200 }, WHITE);

	if (subjectFrameTime > 0.3f)
	{
		if (subjectFrame < frames - 1)
			subjectFrame++;

		subjectFrameTime = 0;
	}
}
void Render::TryChemicalReaction(Texture2D button, bool& tryOn, std::vector<std::string> chemicalReactions)
{
	Rectangle buttonFrame = { 0, 0, (float)button.width / 2, (float)button.height };
	if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 + 100, (float)GetScreenHeight() - 150, (float)button.width / 2, (float)button.height }))
	{
		buttonFrame.x = button.width / 2;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			tryOn = true;
			subjectFrame = 0;
			cellFrame = 0;
			text.clear();
			letterIndex = 0;
		}
	}
	DrawTextureRec(button, buttonFrame, { (float)GetScreenWidth() / 2 + 100, float(GetScreenHeight() - 150) }, WHITE);
}

void Render::Reset(Texture2D button)
{
	Rectangle buttonFrame = { 0, 0, (float)button.width / 2, (float)button.height };
	
	if (CheckCollisionPointRec(GetMousePosition(), { (float)button.width, (float)button.height, 200, (float)GetScreenHeight() - 300 }))
	{
		buttonFrame.x = button.width / 2;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			bowlColor = { 255, 255, 255, 0 };
			mixCount = 0;

			for (auto it = indexes.begin(); it != indexes.end(); it++)
				textures->RestoreFlask(*it);
			tryOn = false;
			subjectFrame = 0;
			indexes.clear();
			chemicalReactions.clear();
			cellFrame = 0;
			reactionIndex = 0;
			text.clear();
			letterIndex = 0;
			stats = "-Subject is ready for experimental tests";
		}
	}
	DrawTextureRec(button, buttonFrame, { 200, (float)GetScreenHeight() - 300 }, WHITE);
}

void Render::DrawGuideBook(Texture2D book, int index)
{
	Rectangle page = { index * book.width / 10, 0, (float)book.width / 10, (float)book.height };

	DrawTextureRec(book, page, { 500, 100, }, WHITE);
}
void Render::Draw()
{
	for (int i = 0; i < 10; i++)
		if (CheckCollisionPointRec(GetMousePosition(), { textures->flaskPositionX[i], textures->flaskPositionY[i], 25, 50 }) && !isEquipped && isDropped)
			index = i;

	DrawTexture(textures->room, 0, 0, WHITE);

	input->DragAndDrop(textures->flaskPositionX[index], textures->flaskPositionY[index], textures->flasks[index], textures->firstPosition[index], isEquipped, isDropped);

	
	if (CheckCollisionPointRec({ textures->flaskPositionX[index], textures->flaskPositionY[index] }, { 660, 740, 200, 400 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		chemicalReactions.push_back(chemicalCompounds[index]);
		mixCount++;
		isOnBowl = true;
	}
	else
		isOnBowl = false;

	if (isOnBowl && mixCount <= 2)
	{

		bowlColor.a = 255;
		bowlColor.r = 255 - (sqrt(pow((255 - (bowlColor.r)), 2) + pow((255 - (color[index].r)), 2) / 2));
		bowlColor.g = 255 - (sqrt(pow((255 - (bowlColor.g)), 2) + pow((255 - (color[index].g)), 2) / 2));
		bowlColor.b = 255 - (sqrt(pow((255 - (bowlColor.b)), 2) + pow((255 - (color[index].b)), 2) / 2));
		indexes.push_back(index);
		textures->RemoveFlask(index);

	}

	if (mixCount > 2)
		mixCount = 2;

	
	if (!tryOn)
		SubjectIdle(textures->subjectIdle, 7);

	else 
	{	if(!isCleared)
		
		if ((chemicalReactions[0] == "H2O" && chemicalReactions[1] == "Cr(OH)3") || (chemicalReactions[1] == "H2O" && chemicalReactions[0] == "Cr(OH)3"))
		{
			SubjectCancer(textures->subjectCancer, 10);
			stats = "-Subject has contained cancer \n-White cells have been destroyed by cancer cells";
		}
		else if ((chemicalReactions[0] == "Na" && chemicalReactions[1] == "H2O") || (chemicalReactions[1] == "Na" && chemicalReactions[0] == "H2O"))
		{
			SubjectBurn(textures->subjectBurn, 7);
			stats = "-Subject has been exposed to 2nd degree burns \n-White cells have not been damaged";
		}
		else if ((chemicalReactions[0] == "U" && chemicalReactions[1] == "Fe") || (chemicalReactions[1] == "U" && chemicalReactions[0] == "Fe") || (chemicalReactions[0] == "U" && chemicalReactions[1] == "H2O") || (chemicalReactions[1] == "U" && chemicalReactions[0] == "H2O"))
		{
			SubjectToxic(textures->subjectToxic, 37);
			stats = "-Subject has been exposed to radioactive chemicals \n-White cells have been destroyed completely";
		}
		else
		{
			SubjectIdle(textures->subjectIdle, 7);
			stats = "-Subject has not experienced any negative changes \n-White cells are still intact";
		}
	}
	
	
	
	DrawTexture(textures->glass, 0, 0, WHITE);
	
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
	if (mixCount == 2)
	{
		TryChemicalReaction(textures->tryButton, tryOn, chemicalReactions);
		
	}

	SubjectStats(stats);

	if (!tryOn)
		CellsUnderMicroscope(textures->cells, true);
	else
	{
		if ((chemicalReactions[0] == "H2O" && chemicalReactions[1] == "Cr(OH)3") || (chemicalReactions[1] == "H2O" && chemicalReactions[0] == "Cr(OH)3"))
			CellsUnderMicroscope(textures->cancerCells, false);

		else if ((chemicalReactions[0] == "U" && chemicalReactions[1] == "Fe") || (chemicalReactions[1] == "U" && chemicalReactions[0] == "Fe"))
			CellsUnderMicroscope(textures->toxicCells, false);

		else
			CellsUnderMicroscope(textures->cells, true);
	}
	
	Reset(textures->resetButton);

	if (CheckCollisionPointRec(GetMousePosition(), { 450, 685, 100, 120 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		isBookOpened = true;
	

	if (IsKeyPressed(KEY_LEFT))
		pageIndex--;

	if (IsKeyPressed(KEY_RIGHT))
		pageIndex++;

	if (pageIndex < 0)
		pageIndex = 9; 
	
	if (pageIndex > 9)
		pageIndex = 0; 

	if (isBookOpened)
	{
		DrawGuideBook(textures->pages, pageIndex);
		DrawTexture(textures->closeX, 950, 120, BLACK);

		if (CheckCollisionPointRec(GetMousePosition(), { 950, 120, 25, 25 }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			isBookOpened = false;
	}

}

void Render::UnloadTextures()
{
	delete textures;
}