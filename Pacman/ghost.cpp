#include "ghost.h"
#include "gamePlay.h"
#include "QDist.h"

//ghosts movment by user choice
void ghost::ghostMove(char& key, char boardGame[][SIZECOL], int row, int col, ghost& currGhost, const Point& pac,bool keepTrack[][SIZECOL]) {
	if (color) {
		if (boardGame[this->getX()][ this->getY()] == '.') {
			setTextColor(Color::MAGENTA);
		}
	}
	draw(boardGame[this->getX()][ this->getY()]);
	if (color) {
		setTextColor(Color::LIGHTRED);
	}
	moveGhost(boardGame,row,col, currGhost,pac,keepTrack);
	draw(GHOST);

}

// after the pacman lose a life we update the ghosts to start location
void ghost::resetGhosts(ghost& ghostGame) {
	draw(' ');
	setX(startGhost.getX());
	setY(startGhost.getY());
	if (color) {
		setTextColor(Color::LIGHTRED);
	}
	draw(GHOST);

}

//print ghosts with color or without
void ghost::printGhost() {
	gotoxy(getX(), getY());
	cout << GHOST;
}

void ghost::setColor(const bool& _color) {
	color = _color;
}

void ghost::setStartGhost(Point _start) {

	startGhost.setX(_start.getX());
	startGhost.setY(_start.getY());
}
void ghost::resetGhostMove() {
	this->countMoveGhosts = 0;
}

void ghost:: setGhostMove() {
	this->countMoveGhosts = countMoveGhosts + 1;
}
int ghost::getGhostMove() {
	return countMoveGhosts;
}