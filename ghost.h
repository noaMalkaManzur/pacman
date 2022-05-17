#pragma once
#include "defineGame.h"
#include "point.h"
#include "io_utils.h"
#include <vector>
static constexpr char GHOST = '$';

class ghost :public Point {

private:
	Point startGhost;
	int countMoveGhosts = 0;
	bool color;
public:
	void setColor(const bool& _color);
	void ghostMove(char& key, char boardGame[][SIZECOL], int row, int col, ghost& currGhost, const Point& pac,bool keepTrack[][SIZECOL]);
	virtual void moveGhost(char boardGame[][SIZECOL], int row, int col, ghost& currGhost, const Point& pac,bool keepTrack[][SIZECOL]) {};
	void resetGhosts(ghost& ghostGame);
	void printGhost();
	void setStartGhost(Point start);
	void setGhostMove();
	int getGhostMove();
	void resetGhostMove();
};

