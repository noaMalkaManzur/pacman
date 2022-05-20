#pragma once
#include "point.h"
#include "defineGame.h"

static constexpr char PACMAN = '@';

class pacman : public Point {
private:
	Point pacStart;
	int live = 3, pointGame = 0, pointCurrGame = 0, countMovePac = 0;
	bool color;
public:
	pacman(int x = 0, int y = 0, bool color = false) : color(color) {
		setX(x);
		setY(y);
	};
	void setPac(Point startPac);
	void setColor(const bool& _color);
	void setLive(char& key);
	void setPointGame();
	void setPointGame(int _point);
	void setCountMovePac();
	void setPointCurrGame();
	int getLive()const;
	int getPointGame()const;
	int getCountMovePac();
	int getPointCurrGame()const;
	void resetPointCurrGame();
	void resetPac();
	void printPac()const;
	void MovePac(char Key, char board[][SIZECOL], int row, int col);
	void pacStartPos(Point start);
	void addFruitToPoint(int fruit);
};



