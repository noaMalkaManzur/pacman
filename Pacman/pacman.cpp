#include "pacman.h"

//pacman movment 
void pacman::MovePac(char key, char board[][SIZECOL],int row, int col) {

	draw(' ');
	move(key, board,row,col);
	draw(PACMAN);
}

//after lossing life we move the pacman to start location
void pacman::resetPac() {
	draw(' ');
	setX(pacStart.getX());
	setY(pacStart.getY());
	draw(PACMAN);
	Sleep(100);
}
//set point of pacman
void pacman::setPac(Point startPac) {
	setX(startPac.getX());
	setY(startPac.getY());

}
// set starting point of pacman
void pacman::pacStartPos(Point start) {

	pacStart.setX(start.getX());
	pacStart.setY(start.getY());
}

//update the live 
void pacman::setLive(char& key) {
	this->live = live - 1;
	key = 's';//after lossing life the pacman waits till the user press any move	
}
//update the pointGame of the pacman
void pacman::setPointGame() {
	this->pointGame = pointGame + 1;
}

int pacman::getLive()const {
	return live;
}
int pacman::getPointGame()const {
	return pointGame;
}
//print pacman
void pacman::printPac()const {
	if (color) {
		setTextColor(Color::LIGHTRED);
	}
	draw(PACMAN);
}

void pacman::setColor(const bool& _color) {
	color = _color;
}
void pacman::setPointGame(int _point) {
	pointGame += _point;
}

void pacman::setCountMovePac() {
	this->countMovePac = countMovePac + 1;
}

void pacman::addFruitToPoint(int fruit) {
	pointGame += fruit;
}

int pacman::getPointCurrGame()const {
	return pointCurrGame;
}

void pacman::setPointCurrGame() {
	this->pointCurrGame = pointCurrGame + 1;
}

void pacman::resetPointCurrGame() {
	this->pointCurrGame = 0;
}

int pacman::getCountMovePac() {
	return countMovePac;
}