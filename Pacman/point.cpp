#include "point.h"
#include "board.h"

//print the point with color or without
void Point::draw(char ch) const {

	gotoxy(this->x,this-> y);
	cout << ch;
}
//move the ghosts randomly
char Point::MoveRand() {
	int dir = rand() % 4;
	char key = 'w';
	switch (dir) {
	case 0:
		key = 'w';
		break;
	case 1:
		key = 'a';
		break;
	case 2:
		key = 'd';
		break;
	case 3:
		key = 'x';
		break;
	}
	return key;
}

//constructor points
Point::Point(int x, int y) : x(x), y(y) {};

Point::Point() : Point(x, y) {};

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getX()const {

	return x;
}

int Point::getY()const {
	return y;
}

//move the pacman and the ghosts by the key move
void Point::move(char key, char board[][SIZECOL],int row, int col) {
	bool flag = false;
	switch (key) {

	case 'w': case 'W'://up
		--x;
		if (x < 0) {

			flag = checkTunnel(board,row,col);
			if (flag == true) {
				x = row - 1;
				
			}
			else {
				++x;
			}
		}
		else if (board[x][y] == WALL) {
			++x;
		}
		break;
	case 'x':case 'X'://DOWN
		++x;
		if (x > row - 1) {
			flag = checkTunnel(board,row, col);
			if (flag == true) {
				x = 0;
			}
			else {
				--x;
			}
		}
		else if (board[x][y] == WALL) {
			--x;
		}

		break;
	case 'a': case'A'://left
		--y;
		if (y < 0) {
			flag = checkTunnel(board,row, col);
			if (flag == true) {
				y = col - 1;
			}
			else {
				++y;
			}
		}
		else if (board[x][y] == WALL) {
			++y;
		}

		break;

	case 'd':case'D'://right
		++y;
		if (y > col - 1) {
			flag = checkTunnel(board,row, col);
			if (flag == true) {
				y = 0;
			}
			else {
				--y;
			}
		}
		else if (board[x][y] == WALL) {
			--y;
		}
		
		break;

	case 'S':case 's'://stay

		break;

	}
}

bool Point::checkTunnel(char board[][SIZECOL], int row, int col) {
	if (x < 0) {
		if (board[row - 1][y] == '#') {
			return false;
		}
	}
	else if (x > row - 1) {
		if (board[0][y] == '#') {
			return false;
		}
	}
	else if (y < 0) {
		if (board[x][col-1] == '#') {
			return false;
		}
	}
	else {
		if (board[x][0] == '#') {
			return false;
		}
	}
	return true;

}


