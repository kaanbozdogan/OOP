#ifndef BOARDARRAY2D_H
#define BOARDARRAY2D_H

#include "BoardAbstract.h"

using namespace Bozdogan_CSE241_HW5;


class BoardArray2D : public AbstractBoard
{
public:
	BoardArray2D();
	BoardArray2D(const int& height, const int& width);
	
	~BoardArray2D();
	BoardArray2D(const BoardArray2D& other);
	BoardArray2D& operator =(const BoardArray2D& other);
	
	void print() const;
	bool writeToFile(const string& fileName) const;
	bool readFromFile(const string& fileName);
	
	bool setSize(const int& height, const int& width);
	void reset();
	
	bool move(const Direction& direc);
	bool isSolved() const;

	int operator ()(const int& row, const int& col) const;

	bool moveControl(const Direction& direc) const;

private:
	int** board;
};

#endif