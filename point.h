#pragma once
#include "defineGame.h"
#include "io_utils.h"
class Board;
class Point {

	int x = 0, y = 0;
	bool checkTunnel(char board[][SIZECOL], int row, int col);
public:
	Point(int x, int y);
	Point();
	int getX()const;
	int getY()const;
	void setX(int x);
	void setY(int y);
	void draw(char ch)const;
	void move(char key, char board[][SIZECOL], int row, int col);
	char MoveRand();
};
