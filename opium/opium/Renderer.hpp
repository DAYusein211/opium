#include "pch.hpp"
#include "inputHandler.hpp"
#include "Textures.hpp"
class Render
{
private:
	std::string text;
	int letterIndex;
	float delay, frameTime;
	std::string stats;
	std::vector<int>indexes;
	Textures* textures;
	InputHandler* input;
	Color flaskColor, bookColor, fade;
	bool isWritten;
	bool isPreviousPossible, isPossible, switchTransition, isDropped, isUpdated, isEquipped, isBookOpened, isOnBowl;
	int index, mixCount, switchFrame;
	int pageIndex, reactionIndex;
	std::vector<std::string> chemicalCompounds;
	std::vector <std::string> chemicalReactions;
	std::string possibleChemicalReactions[5][2] = { {"Cr(OH)3", "H2O"},
	  {"Na", "H2O"},
	  {"ad", "da"},
	  {"wwg","gwwg"},
	  {"qwwqwq", "gtgtgr"}
	};
	Color bowlColor;
	std::vector<Color> color;
	Vector2 center;
public:

	Render();
	//Renders the game's menu
	void MainMenu(bool& isPlayOn, bool& exit);
	void FadeOut(Color& fadeOut, bool& isOver);
	//Displays stats on screen
	void SubjectStats(std::string& stats);
	void CellsUnderMicroscope(Texture2D cells);
	void TryChemicalReaction(Texture2D button);
	void InitialiseTextures();
	void Draw();
	void UnloadTextures();
};