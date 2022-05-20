#include "Good.h"
#include "QDist.h"

void Good::moveGhost(char boardGame[][SIZECOL], int row, int col, ghost& currGhost, const Point& pac, bool keepTrack[][SIZECOL]) {
	QDist q(0, 0, 0);
	char k;
	bool flag = false, isBest=true;
	if (isBest) {
		k = q.getMinumDistance(keepTrack,row,col, currGhost,pac);
		currGhost.move(k, boardGame,row,col);
	}
	if (currGhost.getGhostMove() == 20) {
		char key = currGhost.MoveRand();
		currGhost.move(key, boardGame,row,col);//after we get the key move we move the ghosts
		currGhost.resetGhostMove();
		flag = true;
		isBest = false;
	}
	 else if (currGhost.getGhostMove() == 5 && flag==true) {
		k = q.getMinumDistance(keepTrack,row,col, currGhost,pac);
		currGhost.move(k, boardGame,row,col);
		isBest = true;
	}
	currGhost.setGhostMove();
	
}	