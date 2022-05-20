#pragma once
#include "defineGame.h"   
#include <time.h>   
#include "point.h"


class fruit : public Point {
private:
	bool color;
	char digit;
	int fruitCountMove;
	bool onBoard;
	static const int FRUIT_AVG_LIFE_TIME = 30;
	static const int FRUIT_AVG_REAPPERING_TIME = 50;
public:
	char digitRandomChar();
	int getDigitNum();
	void randomPointForFruit(int row, int col);
	void MoveFruit(char board[][SIZECOL], int row, int col);
	void setFruitCountMove(int count);
	int getFruitMove();
	void setBoolOnBoard(bool onBoard);
	bool getBoolOnBoard();
	const int getAvgLifeTime();
	const int getAvgReapperTime();
	void setColorFruit(const bool& _color);
	void printFruit()const;
};

