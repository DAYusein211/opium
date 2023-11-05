#include <raylib.h>
class Textures
{
public:
	Texture2D room, shadows, flask, flaskHolder;
	std::vector<Texture2D> flasks;
	std::vector<float> flaskPositionX, HolderPositionX;
	float flaskPositionY = 615;

	std::string GetDirectory(int number);
	void SetSize(Texture2D* texture, int height, int width);
	void InitialiseTextures();
	~Textures();
	
};