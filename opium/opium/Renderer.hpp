#include "pch.hpp"
#include "inputHandler.hpp"
#include "Textures.hpp"
class Render
{
private:
	std::vector<std::string> chemicalCompounds;
	std::vector <std::string> chemicalReactions;
	std::vector<int>indexes;
	std::vector<Color> color;
	std::string text, stats;
	std::string possibleChemicalReactions[5][2] = { {"Cr(OH)3", "H2O"},
	  {"Na", "H2O"},
	  {"U", "Fe"},
	  {"Fe","H2O"},
	  {"Ca", "Mg"}
	};
	Textures* textures;
	InputHandler* input;
	Color bowlColor, flaskColor, bookColor, fade;
	Vector2 center;
	float delay, frameTime, subjectFrameTime;
	bool clearText, isCleared, switchTransition, isDropped, isUpdated, isEquipped, isBookOpened, isOnBowl, tryOn, idle, toxic, cancer, burn;
	int index, mixCount, cellFrame, subjectFrame, pageIndex, reactionIndex, letterIndex, columnIndex;

	
	
public:

	Render();

	//Renders the game's menu
	void MainMenu(bool& isPlayOn, bool& exit);

	void FadeOut(Color& fadeOut, bool& isOver);

	void Reset(Texture2D resetButton);

	//Displays stats on screen
	void SubjectStats(std::string& stats);

	//Draws cells under microscope
	void CellsUnderMicroscope(Texture2D cells, bool isNormal);

	//Idle animation
	void SubjectIdle(Texture2D subject, int frames);

	//Cancer animation
	void SubjectCancer(Texture2D subject, int frames);

	//Exposure to radioactive chemicals animation
	void SubjectToxic(Texture2D subject, int frames);

	//Skin burning animation
	void SubjectBurn(Texture2D subject, int frames);

	void DrawGuideBook(Texture2D book, int index);

	//Tries chemical reaction on the subject
	void TryChemicalReaction(Texture2D button, bool& tryOn, std::vector<std::string> chemicalReactions);
	void InitialiseTextures();
	void Draw();
	void UnloadTextures();
};