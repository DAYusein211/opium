class Render
{
public:
	//Renders the game's menu
	void MainMenu(bool& isPlayOn, bool& exit);

	//Displays stats on screen
	void SubjectStats(std::string stats);
	void InitialiseTextures();
	void Draw();
	void UnloadTextures();
};