#include <raylib.h>
class Textures
{
public:
	Texture2D flaskHolder, book, room, shadows, bowl, playButton;
	std::vector<Texture2D> flasks, pages;
	float flaskPositionX[10];
	std::vector<float> HolderPositionX;

	float flaskPositionY[10];
	Vector2 firstPosition[10];

	std::string GetDirectory(int number, std::string object);
	void SetSize(Texture2D* texture, int height, int width);
	void InitialiseTextures();
	void BookOpened(int index);
	void RemoveFlask(int index);
	void RestoreFlask(int index);
	~Textures();
	
};