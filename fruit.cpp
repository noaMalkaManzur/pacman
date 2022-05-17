#include "fruit.h"
//get a random fruit 
char fruit::digitRandomChar() {

	int dir = rand() % 5;
	char digitFruit;
	switch (dir) {
	case 0:
		digitFruit = '5';
		break;
	case 1:
		digitFruit = '6';
		break;
	case 2:
		digitFruit = '7';
		break;
	case 3:
		digitFruit = '8';
		break;

	case 4:
		digitFruit = '9';
		break;
	}
	digit = digitFruit;
	return digitFruit;
}
//get random point for fruit
void fruit::randomPointForFruit(int row, int col) {
	setX(rand() % row);
	setY(rand() % col);
}

// fruit movement
void fruit::MoveFruit(char board[][SIZECOL], int row, int col) {
	if (color) {
		setTextColor(Color::MAGENTA);
	}
	draw(board[this->getX()][ this->getY()]);
	if (color) {
		setTextColor(Color::LIGHTRED);
	}
	char key = MoveRand();
	move(key, board,row,col);
	printFruit();
	setFruitCountMove(fruitCountMove);
}

void fruit::setFruitCountMove(int count) {
	fruitCountMove = count + 1;
}
int fruit::getFruitMove() {
	return fruitCountMove;
}
int fruit::getDigitNum() {
	return digit - '0';
}
void fruit::setBoolOnBoard(bool _onBoard) {
	onBoard = _onBoard;
}
bool fruit::getBoolOnBoard() {
	return onBoard;
}

const int fruit::getAvgLifeTime() {
	return FRUIT_AVG_LIFE_TIME;
}

const int  fruit::getAvgReapperTime() {
	return FRUIT_AVG_REAPPERING_TIME;
}

void fruit:: setColorFruit(const bool& _color) {
	color = _color;
}

void fruit::printFruit()const {
	if (color) {
		setTextColor(Color::LIGHTRED);
	}
	draw(digit);
}