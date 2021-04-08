#ifndef BOARDABSTRACT_H
#define BOARDABSTRACT_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include "Namespace.h"

using namespace Bozdogan_CSE241_HW5;


class AbstractBoard
{
public:
	AbstractBoard();
	virtual ~AbstractBoard();
	
	virtual void print() const = 0;
	virtual bool writeToFile(const string& fileName) const = 0;
	virtual bool readFromFile(const string& fileName) = 0;
	
	virtual bool setSize(const int& height, const int& width) = 0;
	virtual void reset() = 0;
	
	virtual bool move(const Direction& direc) = 0;
	virtual bool isSolved() const = 0;

	virtual int operator ()(const int& row, const int& col) const = 0;
	bool operator ==(const AbstractBoard* other) const;

	static int numberOfBoards();
	int numberOfMoves();
	Direction lastMove();

	int getSizeRow() const;
	int getSizeCol() const;

	virtual bool moveControl(const Direction& direc) const = 0;
	
protected:
	int emptyRow, emptyCol;
	int sizeRow, sizeCol;

	Direction moveLast;
	int moveCount;
	static int boardCount;

	static const int border;
	static const int empty;

	bool sizeControl(const int& height, const int& width) const;
};

#endif