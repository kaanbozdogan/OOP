#ifndef FIRSTHW_H
#define FIRSTHW_H

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


enum Direction {Up, Down, Left, Right, None};

const int border = -1;
const int empty = 0;


int getSize();
void initBoard(int board[][11], int emptyCell[2], int size[2]);
void shuffle(int board[][11], int emptyCell[2], int size[2]); //shuffles sizeHeight*sizeWidth times

bool moveControl(int board[][11], int emptyCell[2], Direction direc); //Controls if move is valid
void randomMove(int board[][11], int emptyCell[2]);
void updateBoard(int board[][11], int emptyCell[2], Direction direc); //Updates the board with moving the empty cell

void assignBoard(int board[][11], int emptyCell[2], int boardTemp[][11], int emptyCellTemp[2]); //copies board to boardTemp
void printBoard(int board[][11],int size[2]);
void printControlInf();
bool isFinished(int board[][11], int size[2]);


#endif
