#include "defineGame.h"
void printMenu() {
	cout << "********************************************************" << endl;
	cout << "*(1) Start a new game with out color                   *" << endl;
	cout << "*(2) Start a new game with color                       *" << endl;
	cout << "*(8) Present instructions and keys                     *" << endl;
	cout << "*(9) EXIT                                              *" << endl;
	cout << "********************************************************" << endl;
}
void printMenuGhost() {
	cout << "********************************************************" << endl;
	cout << "*(a) BEST                                              *" << endl;
	cout << "*(b) GOOD                                              *" << endl;
	cout << "*(c) NOVICE                                            *" << endl;
	cout << "********************************************************" << endl;
}

void PresentInstructionsandKeys() {

	instructionGame();
	instructionKey();
}

void instructionGame() {
	cout << "**************************************************************" << endl;
	cout << "*InstructionGame:                                            *" << endl;
	cout << "*Pac-Man is an action maze chase video game.                 *" << endl;
	cout << "*The player controls the pacman through an enclosed maze.    *" << endl;
	cout << "*The objective of the game is to eat all of the dots placed  *" << endl;
	cout << "*in the maze while avoiding two ghosts that pursue him       *" << endl;
	cout << "*If Pacman makes contact with a ghost, he will lose a life.  *" << endl;
	cout << "*The game ends when all lives are lost.                      *" << endl;
	cout << "**************************************************************" << endl;
}

void instructionKey() {
	cout << "****************************" << endl;
	cout << "*InstructionKey:           *" << endl;
	cout << "*To go left press  a or A  *" << endl;
	cout << "*To go right press d or D  *" << endl;
	cout << "*To go up press w or W     *" << endl;
	cout << "*To go down press x or X   *" << endl;
	cout << "*To stay press s or S      *" << endl;
	cout << "****************************" << endl;
	cout << "Enter a number or letter to return to the menu" << endl;

}

void afterInstruction() {
	char c;
	cin >> c;
	clear_screen();
}

