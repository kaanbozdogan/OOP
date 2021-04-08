#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include "BoardAbstract.h"

using namespace Bozdogan_CSE241_HW5;


class BoardArray1D : public AbstractBoard
{
public:
	BoardArray1D();
	BoardArray1D(const int& height, const int& width);
	
	~BoardArray1D();
	BoardArray1D(const BoardArray1D& other);
	BoardArray1D& operator =(const BoardArray1D& other);
	
	void print() const;
	bool writeToFile(const string& fileName) const;
	bool readFromFile(const string& fileName);
	
	bool setSize(const int& height, const int& width);
	void reset();
	
	bool move(const Direction& direc);
	bool isSolved() const;

	int operator ()(const int& row, const int& col) const;

	bool moveControl(const Direction& direc) const;

	int getSize() const;
	//Finding where inputed 2d coordiantes correspondes to at 1d array
	int getIndexOfCoordinate(const int& y, const int& x) const;

private:
	int* board;
	int size;
};

#endif