#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H

#include "BoardAbstract.h"
#include <vector>

using namespace Bozdogan_CSE241_HW5;


class BoardVector : public AbstractBoard
{
public:
	BoardVector();
	BoardVector(const int& height, const int& width);
	BoardVector(const BoardVector& other);
	~BoardVector();
	
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
	vector< vector<int> > board;
};

#endif