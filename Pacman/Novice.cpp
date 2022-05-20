#include "Novice.h"

void Novice::moveGhost(char boardGame[][SIZECOL], int row, int col, ghost& currGhost, const Point& pac, bool keepTrack[][SIZECOL]) {
	
	char key = currGhost.MoveRand();
	currGhost.move(key, boardGame,row,col);//after we get the key move we move the ghosts
	
}