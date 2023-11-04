#include "pch.hpp"

void Render::Draw()
{
	DrawTexture(texture, 0, 0, WHITE);
}

void Render::DrawStand(int x, int y)
{
	DrawTexture(texture, x, y, WHITE);
}

void Render::DrawPotion(int x, int y)
{
	DrawTexture(texture, x, y, WHITE);
}