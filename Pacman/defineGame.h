#pragma once
#include <iostream>
#include "io_utils.h"
using namespace std;
static int constexpr SIZEROW = 25;
static int constexpr SIZECOL = 80;

void printMenu();
void PresentInstructionsandKeys();
void instructionKey();
void instructionGame();
void afterInstruction();
void printMenuGhost();

