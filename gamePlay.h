#pragma once
#include "defineGame.h"
#include "board.h"
#include <string.h>
static constexpr int ESC = 27;
static constexpr int LOSINGLIFE = 0;

class gamePlay {
private:
	int gamePoint;
	bool color = false;
public:
	void setGamePoint(int gamePoints);
	void getBoardFromFile(int fileChoice);
	void setColor(const bool& without);
	bool runGame(char keyForGhost,Board& boardGame);
	void EscMode();
	void startBoard(char keyForGhost,Board& boardGame);
	void switchMenu();
	void victoryGame();
	void endOfTheGame();
	void announcementOfTheGame();
	bool checkValidMove(char move);
	char switchMenuGhost();
	vector <string> newFileOptaion(Board& board, int userChoice);
	int menuFile();
};

