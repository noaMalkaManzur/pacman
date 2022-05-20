#pragma once
#include <queue>
#include "board.h"
class QDist
{
private:
	int rowD;
	int colD;
	char direction;
public:
	QDist(int x, int y, char key) : rowD(x), colD(y), direction(key) {};
	char getMinumDistance(bool keepTrack[][SIZECOL],int row, int col, ghost& currGhost, const Point& pac);
	int getRow()const;
	int getCol()const;
	void setRow(int x);
	void setCol(int y);
	char calDistance(QDist& source, bool keepTrack[SIZEROW][SIZECOL],int row, int col, const Point& pac);
	const char& getDirection()const;
};

