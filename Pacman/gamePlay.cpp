#include "gamePlay.h"

//check valid key from user
bool gamePlay::checkValidMove(char move) {
	if (move == 'a' || move == 'A' || move == 'X' || move == 'x' || move == 'w' || move == 'W' || move == 'd' || move == 'D' || move == 's' || move == 'S')
		return true;
	return false;
}

//pacman won the game
void gamePlay::victoryGame() {

	clear_screen();
	cout << "You won !!! great job " << endl;
	announcementOfTheGame();
}
//pacman lost, the game ended
void gamePlay::endOfTheGame() {
	clear_screen();
	cout << "You lost !!! GAME OVER " << endl;
	announcementOfTheGame();
}
//after losing or winning there will be announcement and presentation of the menu
void gamePlay::announcementOfTheGame() {
	char ch;
	cout << "press any key to the menu" << endl;
	ch = _getch();
	clear_screen();
}
// start the game
bool gamePlay::runGame(char keyForGhost,Board& boardGame) {

	boardGame.setColor(color);
	startBoard(keyForGhost,boardGame);
	char currMove = _getch(), prevMove = currMove;
	bool isFirstMove = true, isValid;
	while (boardGame.getPacman().getPointCurrGame() != gamePoint && boardGame.getPacman().getLive() != LOSINGLIFE) {
		if (currMove == ESC) {
			EscMode();
			boardGame.printBoard();
			boardGame.MoveAllCreature(currMove);
			if (isFirstMove == false) {
				currMove = prevMove;
			}
			else {
				currMove = _getch();
			}
		}
		else {
			boardGame.getPacman().setCountMovePac();
			//now we have a counter for pacman
		}
		isFirstMove = false;
		isValid = checkValidMove(currMove);
		if (!isValid) {
			currMove = prevMove;
		}
		boardGame.fruitDisapper();
		boardGame.MoveAllCreature(currMove);//move the pacman and ghost
		Sleep(300);
		if (_kbhit()) {
			prevMove = currMove;
			currMove = _getch();
		}
	}
	if (boardGame.getPacman().getLive() == LOSINGLIFE) {//game over
		setColor(false);
		setTextColor(Color::LIGHTGREY);
		endOfTheGame();
		return false;
	}
	else if (boardGame.getPacman().getPointCurrGame() == gamePoint) {//next level
		boardGame.getPacman().resetPointCurrGame();
		return true;
	}


}
//pause move
void gamePlay::EscMode() {
	char getMove;
	clear_screen();
	cout << "Game paused, press ESC again to continue" << endl;
	getMove = _getch();
	while (getMove != ESC) {
		getMove = _getch();
	}
}

//create the board and presentation of the board, pacman and ghosts
void gamePlay::startBoard(char keyForGhost,Board& boardGame) {
	int countPoints;
	countPoints = boardGame.countPointGame();
	gamePoint = countPoints;
	boardGame.printBoard();//print the board for start
	boardGame.getCorOfGhosts(keyForGhost);
	boardGame.printGhostGame();
	boardGame.getCorOfPac();
	boardGame.getPacman().printPac();
	boardGame.putFruitOnBoard();
	boardGame.getFruit().setBoolOnBoard(true);
}
//switch case menu
void gamePlay::switchMenu() {
	char keyForGhost;
	int fileChoice;
	string userChoice;
	printMenu();
	cout << "enter choice" << endl;
	while (userChoice[0] !=9) {
		
		switch (userChoice[0]) {

		case '1':
			setColor(false);
			clear_screen();
			fileChoice = menuFile();
			getBoardFromFile(fileChoice);
			userChoice[0] = 0;
			break;
		case '2':
			setColor(true);
			clear_screen();
			fileChoice = menuFile();
			getBoardFromFile(fileChoice);
			userChoice[0] = 0;
			break;
		case '8':
			clear_screen();
			PresentInstructionsandKeys();
			afterInstruction();
			userChoice[0] = 0;
			break;
		case '9':
			userChoice = 9;
			break;

		default:
			clear_screen();
			printMenu();
			cout << "enter choice" << endl;
			cin >> userChoice;
			break;
		}
	}

}

int gamePlay::menuFile() {
	int userChoice;
	cout << "Please choose" << endl;
	cout << "1.Take file from directory" << endl;
	cout << "2.Enter a name file without suffix screen" << endl;
	cin >> userChoice;
	clear_screen(); 
	while (userChoice != 2 && userChoice != 1) {
		cin >> userChoice;
	}
	return userChoice;
}


vector <string> gamePlay::newFileOptaion(Board& board, int userChoice) {
	bool found=false;
	vector <string> name;
	name= board.getFileFromDir();
	vector <string> tmpName;
	tmpName.resize(1);
	if (userChoice == 1) {
		return name;
	}
	else {
		cin >> tmpName[0];
		for (auto& file : name) {
			if (file.compare(tmpName[0])==0) {
				found = true;
				return tmpName;
			}
		}
		if (found == false) {
			name.resize(0);
		}
	}
	return name;
}

void gamePlay::setColor(const bool& _color) {
	color = _color;
}

// get board from file
void gamePlay::getBoardFromFile(int fileChoice) {
	int i;
	char key;
	char keyForGhost;
	bool check = true;
	Board boardGame;
	vector<string>fileName = newFileOptaion(boardGame, fileChoice);
	if (fileName.size()==0) {
		cout << "Sorry, there is no file..." << "Please enter a name file, press any single key to return" << endl;
		cin >> key;
		return;
	}
	keyForGhost = switchMenuGhost();
	for (i = 0;i < fileName.size() && check == true; ++i) {
		boardGame.createBoardFromFile(fileName[i]);
		check = runGame(keyForGhost,boardGame);
		clear_screen();
	}
	if (check == true) {
		if (i = fileName.size()) {
			cout << "great work!!" << "Your points are: " << boardGame.getPacman().getPointGame()<<endl;
			cout << "press any single key to return to menu";
			cin >> key;
		}
		clear_screen();
	}
	else {
		return;
	}
}

void gamePlay::setGamePoint(int gamePoints) {
	gamePoint = gamePoints;
}
// switch menu for ghost movement
char gamePlay::switchMenuGhost() {
	char userChoice;
	printMenuGhost();
	cout << "enter choice" << endl;
	cin >> userChoice;

	while (userChoice != 'a' && userChoice != 'b' && userChoice != 'c') {
		switch (userChoice) {

		case 'a':
			userChoice = 'a';
			break;
		case 'b':
			userChoice = 'b';
			break;
		case 'c':
			userChoice = 'c';
			break;
		default:
			clear_screen();
			printMenuGhost();
			cout << "enter choice" << endl;
			cin >> userChoice;
			break;
		}

	}
	return userChoice;
}
