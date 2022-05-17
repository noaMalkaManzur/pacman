#include "board.h"
int Board::currGhost = 2;
// get file from dir 
vector <string> Board::getFileFromDir() {

	vector<string>FileName;
	fs::path p = fs::current_path();
	string ext(".screen");
	for (auto& p : fs::recursive_directory_iterator(p))
	{
		if (p.path().extension() == ext) {
			FileName.push_back(p.path().stem().string());
		}
	}
	return FileName;

}
// seting the coordinate of ghosts from arr points
void Board::getCorOfGhosts(char keyForGhost) {

	int i, j = 2;
	for (i = 0; i < (currGhost - 2);++i, ++j){
		setGhostFromChoice(keyForGhost, i);
		arrGhosts[i]->setX(arrPoints[j].getX());
		arrGhosts[i]->setY(arrPoints[j].getY());
		arrGhosts[i]->setStartGhost(arrPoints[j]);
		
	}
}

void Board::setGhostFromChoice(char keyForGhost, int index) {
	if (keyForGhost == 'a') {
		arrGhosts[index] = new Best;
	}
	else if (keyForGhost == 'b') {
		arrGhosts[index] = new Good;
	}
	else if (keyForGhost == 'c') {
		arrGhosts[index] = new Novice;
	}
}

//set coordinate pacman from point arr
void Board::getCorOfPac() {

	pac.setPac(arrPoints[0]);
	pac.pacStartPos(arrPoints[0]);
}
// crearting the board from file
void Board::createBoardFromFile(string fileName) {
	currGhost = 2;
	char ch;
	bool flag = false, fEof = false, first = true;
	int row = 0, col = 0, rowForbiden = 0, colForbiden = 0, maxCol = -1, count = 0, points;
	fstream boardName;
	fileName.append(".screen");
	boardName.open(fileName, ios::in);
	if (!boardName) {//if file does not load good
		clear_screen();
		cout << "file does not load good, we are mooving you to the next file" << endl;
		clear_screen();
		return;
	}

	while (!fEof) {

		boardName.get(ch);
		if (flag == true && row > (rowForbiden + 2)) {
			flag = false;
		}
		if (flag == true && row >= rowForbiden && row <= (rowForbiden + 2) && col <= (colForbiden + 20) && col >= colForbiden) {
			boardGame[row][col] = ' ';
			count++;
			col++;
		}
		else if (col < maxCol || maxCol == -1) {
			if (ch == '&') {
				Data(OPRAND, row, col);
				boardGame[row][col] = '&';
				flag = true;
				rowForbiden = row;
				colForbiden = col;
				count++;
				col++;
			}
			else if (ch == PACMAN) {
				boardGame[row][col] = ' ';// keep a place for pac
				Data(PACCOR, row, col);
				col++;
			}
			else if (ch == GHOST) {
				boardGame[row][col] = ' ';
				Data(currGhost, row, col);
				currGhost++;
				col++;
			}
			else if (ch == WALL) {
				boardGame[row][col] = WALL;
				col++;
			}
			else if (ch == '%') {
				boardGame[row][col] = ' ';
				col++;
			}
			else if (ch == ' ') {
				boardGame[row][col] = BREADCRUMBS;
				col++;
			}
		}
		if (ch == '\n') {

			while (col < maxCol) {// if the line smaller the the first row put space 
				boardGame[row][col] = ' ';
				col++;
			}

			if (row == 0) {
				if (flag == true) {
					col = col + 19 - count;
				}
				maxCol = col;
			}
			row++;
			col = 0;
		}
		if (boardName.eof()) {
			fEof = true;
		}

	}
	arrGhosts.resize(currGhost - 2);
	logSizeRow = row;
	logSizeCol = maxCol;
}
//set the creature game to his starting point
void Board::Data(int index, int row, int col) {

	arrPoints[index].setX(row);
	arrPoints[index].setY(col);
}

fruit& Board::getFruit() {
	return fruitGame;
}
//print board with colors or without
void Board::printBoard() {

	clear_screen();
	int i, j;
	for (i = 0; i < logSizeRow; i++) {

		for (j = 0;j < logSizeCol; j++) {

			if (color) {
				if (boardGame[i][j] == WALL) {
					setTextColor(Color::CYAN);
				}
				else {
					setTextColor(Color::MAGENTA);
				}
			}
			cout << boardGame[i][j];

		}
		cout << endl;
	}
	printstats(arrPoints[1].getX(), arrPoints[1].getY());
}
 
int Board::getRow() {
	return logSizeRow;
}

int Board::getCol() {
	return logSizeCol;
}

char Board::getPoint(int x, int y) {

	return boardGame[x][y];
}

//checks the location of the pacman checks if run into ghost or breadcrumbs
void Board::checkBoard(char& key) {

	// checks if pac run into ghost1 and then we update life
	for (auto& ghost : arrGhosts) {
		if (pac.getX() == ghost->getX() && ghost->getY() == pac.getY()) {
			pac.setLive(key);
			pac.resetPac();
			for (auto& ghost : arrGhosts) {
				ghost->resetGhosts(*ghost);
			}
		}
	}
	// checks if pac run into breadcrumbs and then we update pointgame
	if (getPoint(pac.getX(), pac.getY()) == BREADCRUMBS) {
		pac.setPointCurrGame();
		pac.setPointGame();
		updateBoard();
	}
	if (fruitMeetPac() == true) {
		putFruitOnBoard();
	}

	printstats(arrPoints[1].getX(), arrPoints[1].getY());//print the score and the point
}
//this function resize the array of ghosts to new size according to file
void Board::resizeArrGhost(int sizeFromFile) {
	arrGhosts.resize(sizeFromFile);
}

vector <ghost*>& Board::getArrGhost() {

	return arrGhosts;
}
//printig all array ghost 
void Board::printGhostGame() {
	if (color) {
		setTextColor(Color::LIGHTRED);
	}
	for (auto& ghost : arrGhosts) {
		ghost->printGhost();
	}
	
}

// move the pacman and ghosts
void Board::MoveAllCreature(char& key) {
	bool keepTrack[SIZEROW][SIZECOL];
	static bool delay = false;
	pac.MovePac(key, boardGame,logSizeRow,logSizeCol);
	checkBoard(key);
	if (!delay) {
		for (auto& ghost : arrGhosts) {
			createArrTrack(keepTrack);
			ghost->setColor(color);
			keepTrack[ghost->getX()][ghost->getY()] = false;
			ghost->ghostMove(key,boardGame, logSizeRow,logSizeCol, *ghost,pac,keepTrack);
			keepTrack[ghost->getX()][ghost->getY()] = true;
			keepTrack[pac.getX()][pac.getY()] = false;

		}
		checkBoard(key);
		if (fruitGame.getBoolOnBoard() == true) {
			checkLocationFruit();
			fruitGame.MoveFruit(boardGame,logSizeRow,logSizeCol);
		}
		delay = true;
	}
	else {
		delay = false;
	}

}

//print the score and the points
void Board::printstats(int row, int col) {

	gotoxy(row, col);
	cout << "GamePoints:" << pac.getPointGame();
	gotoxy(row + 1, col);
	cout << "Lives:     " << pac.getLive();
	hideCursor();
}

//update the board in the location to space
void Board::updateBoard() {

	boardGame[pac.getX()][pac.getY()] = SPACE;
}

pacman& Board::getPacman() {
	return pac;
}

void Board::setColor(const bool& _color) {
	pac.setColor(_color);
	fruitGame.setColorFruit(_color);
	color = _color;
}

const bool& Board::getColor() {
	return color;
}

int Board::countPointGame() {
	int i, j, count = 0;
	for (i = 0;i < logSizeRow;++i) {
		for (j = 0;j < logSizeCol;++j) {
			if (boardGame[i][j] == '.') {
				count++;
			}
		}
	}
	return count;
}

// we update point game after pacman eats fruit
bool Board::fruitMeetPac() {
	bool meet = false;
	if (fruitGame.getX() == pac.getX() && fruitGame.getY() == pac.getY()) {
		pac.addFruitToPoint(fruitGame.getDigitNum());
		meet = true;
	}
	return meet;
}
// fruit meet game point and life
bool Board::fruitMeetOprand() {
	bool meet = false;
	int furitX = fruitGame.getX(), oparndX = arrPoints[1].getX();
	int furitY = fruitGame.getY(), oparndY = arrPoints[1].getY();
	if (furitY < (oparndY + 20) && furitY >= oparndY && furitX >= oparndX && furitX < (oparndX + 3)) {
		meet = true;
	}
	return meet;
}

//if the fruit tuch a wall we get a new point
bool Board::fruitMeetWall() {
	bool meet = false;
	if (boardGame[fruitGame.getX()][fruitGame.getY()] == WALL) {
		meet = true;
	}
	return meet;
}
// if the fruit tuch a ghost
bool Board::fruitMeetGhost() {
	bool meet = false;
	for (auto& ghost : arrGhosts) {
		if (fruitGame.getX() == ghost->getX() && fruitGame.getY() == ghost->getY()) {
			meet = true;
		}
	}
	return meet;
}
void Board::putFruitOnBoard() {
	
	fruitGame.randomPointForFruit(logSizeRow, logSizeCol);
	checkLocationFruit();// finding the right place
	fruitGame.digitRandomChar();
	fruitGame.MoveFruit(boardGame,logSizeRow,logSizeCol);

}

void Board::checkLocationFruit() {

	bool meetGhost = fruitMeetGhost(), meetWall = fruitMeetWall(), meetPac = fruitMeetPac(), meetOprand = fruitMeetOprand();
	while (meetGhost == true || meetWall == true || meetPac == true || meetOprand == true) {
		if (color) {
			if (boardGame[fruitGame.getX()][fruitGame.getY()] == '#') {
				setTextColor(Color::LIGHTBLUE);
			}
			else {

			setTextColor(Color::MAGENTA);
			}
		}
		fruitGame.draw(boardGame[fruitGame.getX()][fruitGame.getY()]);
		if (color) {
			setTextColor(Color::LIGHTRED);
		}
		fruitGame.randomPointForFruit(logSizeRow, logSizeCol);
		meetGhost = fruitMeetGhost(), meetWall = fruitMeetWall(), meetPac = fruitMeetPac(), meetOprand = fruitMeetOprand();
	}
}
// after random move the fruit will disapper
void Board::fruitDisapper() {

	if (rand() % fruitGame.getAvgLifeTime() == 0 && fruitGame.getBoolOnBoard() == true) {
		fruitGame.setBoolOnBoard(false);
		if (color) {
			if (getPoint(fruitGame.getX(), fruitGame.getY() == '.')) {
				setTextColor(Color::MAGENTA);
			}
		}
		fruitGame.draw(getPoint(fruitGame.getX(),fruitGame.getY()));
		if (color) { setTextColor(Color::LIGHTRED); };
		fruitGame.setFruitCountMove(-1);
	}
	else if (fruitGame.getBoolOnBoard() == false && rand() % fruitGame.getAvgReapperTime() == 0) {
		fruitGame.setBoolOnBoard(true);
		putFruitOnBoard();
	}

}


// To keep track of visited QDist and marking wall as visited
void Board::createArrTrack(bool keepTrack[][SIZECOL]) {

	int i, j;
	for (i = 0; i < logSizeRow; ++i) {
		for (j = 0; j < logSizeCol; ++j) {
			if (boardGame[i][j] == '#') {
				keepTrack[i][j] = true;
			}
			else {
				keepTrack[i][j] = false;
			}
		}
	}
	
	for (auto& ghost : arrGhosts) {
		   keepTrack[ghost->getX()][ghost->getY()] = true;
	}
}