#include "pch.hpp"


Game::Game(int width, int height, const char* title)
{
	InitWindow(width, height, title);
};



void Game::Run()
{
	int standX1 = 650, standY1 = 575, standX2 = 850, standY2 = 575, potionX =  584, potionY = 580, counter = 0;
	Render room, shadows, stand, potion1, potion2, potion3, potion4, potion5, potion6, potion7, potion8, potion9, potion10;
	room.texture = LoadTexture("../assets/noshadowroom.png");
	stand.texture = LoadTexture("../assets/stoika.png");
	potion1.texture = LoadTexture("../assets/kolba1.png");
	potion2.texture = LoadTexture("../assets/kolba2.png");
	potion3.texture = LoadTexture("../assets/kolba3.png");
	potion4.texture = LoadTexture("../assets/kolba4.png");
	potion5.texture = LoadTexture("../assets/kolba5.png");
	potion6.texture = LoadTexture("../assets/kolba6.png");
	potion7.texture = LoadTexture("../assets/kolba7.png");
	potion8.texture = LoadTexture("../assets/kolba8.png");
	potion9.texture = LoadTexture("../assets/kolba9.png");
	potion10.texture = LoadTexture("../assets/kolba10.png");
	shadows.texture = LoadTexture("../assets/shadows.png");
	room.texture.width = 1600;
	room.texture.height = 900;
	stand.texture.width = 200;
	stand.texture.height = 100;
	shadows.texture.width = 1600;
	shadows.texture.height = 900;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		

		room.Draw();
		stand.DrawStand(standX1, standY1);
		stand.DrawStand(standX2, standY2);
		potion1.DrawPotion(potionX, potionY);
		potion2.DrawPotion(potionX + 35, potionY);		
		potion3.DrawPotion(potionX + 70, potionY);		
		potion4.DrawPotion(potionX + 105, potionY);		
		potion5.DrawPotion(potionX + 140, potionY);		
		potion6.DrawPotion(potionX + 200, potionY);		
		potion7.DrawPotion(potionX + 235, potionY);		
		potion8.DrawPotion(potionX + 270, potionY);		
		potion9.DrawPotion(potionX + 305, potionY);
		potion10.DrawPotion(potionX + 340, potionY);

		shadows.Draw();
		EndDrawing();
	}

}
Game::~Game()
{	

	CloseWindow();
}