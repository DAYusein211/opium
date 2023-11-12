class Render
{
public:
	//Render();
	//Renders the game's menu
	void MainMenu(bool& isPlayOn, bool& exit);
	void FadeOut(Color& fadeOut, bool& isOver);
	//Displays stats on screen
	void SubjectStats(std::string stats);
	void CellsUnderMicroscope(Texture2D cells);
	void TryChemicalReaction(Texture2D button);
	void InitialiseTextures();
	void Draw();
	void UnloadTextures();
};