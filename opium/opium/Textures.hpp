#include <raylib.h>
class Textures
{
public:
	Texture2D room, shadows, flask, flaskHolder;
	std::vector<Texture2D> flasks;

	float flaskPositionX[10];
	std::vector<float> HolderPositionX;

	float flaskPositionY[10];
	Vector2 firstPosition[10];

	std::string GetDirectory(int number);
	void SetSize(Texture2D* texture, int height, int width);
	void InitialiseTextures();
	~Textures();
	
};