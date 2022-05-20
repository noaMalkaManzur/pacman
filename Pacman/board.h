#pragma once 
#include <fstream>
#include <iostream>
#include <filesystem>
#include "defineGame.h"
#include "pacman.h"
#include "point.h"
#include "ghost.h"
#include "fruit.h"
#include "Best.h"
#include "Novice.h"
#include "Good.h"
static constexpr char WALL = '#';
static constexpr char BREADCRUMBS = '.';
static constexpr char SPACE = ' ';
namespace fs = std::filesystem;
class fruit;

class Board {
	enum { PACCOR, OPRAND };
	static int currGhost;
	char boardGame[SIZEROW][SIZECOL];
	Point arrPoints[6];
	vector <ghost*> arrGhosts;
	int logSizeRow = 0, logSizeCol = 0;
	bool color;
	pacman pac;
	fruit fruitGame;
public:
	int getRow();
	void setColor(const bool& _color);
	pacman& getPacman();
	vector <string> getFileFromDir();
	int getCol();
	const bool& getColor();
	char getPoint(int x, int y);
	void getCorOfPac();
	void getCorOfGhosts(char keyForGhost);
	void setGhostFromChoice(char keyForGhost, int index);
	fruit& getFruit();
	void createBoardFromFile(string fileName);
	void checkBoard(char& key);
	void updateBoard();
	void printBoard();
	void printstats(int row, int col);
	void MoveAllCreature(char& key);
	void Data(int index, int row, int col);
	void resizeArrGhost(int sizeFromFile);
	void printGhostGame();
	vector <ghost*>& getArrGhost();
	int countPointGame();
	void createArrTrack(bool keepTrack[][SIZECOL]);
	void fruitDisapper();
	bool fruitMeetPac();
	bool fruitMeetWall();
	bool fruitMeetGhost();
	bool fruitMeetOprand();
	void putFruitOnBoard();
	void checkLocationFruit();
	
};