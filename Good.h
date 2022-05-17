#pragma once
#include "ghost.h"
#include "QDist.h"
class Good :public ghost {
public:
	void moveGhost(char boardGame[][SIZECOL], int row, int col, ghost& currGhost, const Point& pac, bool keepTrack[][SIZECOL])override;
};

