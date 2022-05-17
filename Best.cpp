#include "Best.h"

void Best::moveGhost(char boardGame[][SIZECOL],int row, int col, ghost& currGhost, const Point& pac, bool keepTrack[][SIZECOL]) {
	QDist q(0, 0, 0);
	char k;
	k = q.getMinumDistance(keepTrack,row,col, currGhost,pac);
	currGhost.move(k, boardGame,row,col);
	
}

