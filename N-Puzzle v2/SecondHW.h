#ifndef SECONDHW_H
#define SECONDHW_H

#include "FirstHW.h"
#include <fstream>

using namespace std;


void menu(int board[][11], int emptyCell[2], int size[2]);

bool saveBoard(int board[][11], int size[2], string fileName);
bool loadBoard(int board[][11], int size[2], int emptyCell[2], string fileName);

int solve(int board[][11], int size[2], int emptyCell[2]); //tries to solve the problem
bool isLoop(int board[][11], int boardDatabase[][11][11], int size[2]); //looks if there is a loop pattern at moves that made by solving algorithm
bool compareBoard(int board[][11], int temp[][11], int size[2]); //controls if two boards are the same
int updateDatabase(int board[][11], int boardDatabase[][11][11], int size[2]); //saves the last board state to the move database

Direction intelligentMove(int board[][11], int emptyCell[2], int size[2], Direction lastIntelligentMove); //makes a move that gets closer to the final position
int calcHeuristic(int board[][11], int size[2]); //calculates how close the board is to the finishing position
void findFinalPos(int board[][11], int size[2], int currPos[2], int finalPos[2]); //finds a cell's final position
int calcDisstanceToFinalPos(int board[][11], int currPos[2], int finalPos[2]); //Calculates the count of moves that a cell needs to make
int compareHeuristic(int heuristics[4]); //Chooses the closest one to the final position




#endif