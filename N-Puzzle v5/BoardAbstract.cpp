#include "BoardAbstract.h"

const int AbstractBoard::border = -1;
const int AbstractBoard::empty = 0;

int AbstractBoard::boardCount = 0;


AbstractBoard::AbstractBoard() : moveLast(None), moveCount(0), sizeRow(0), sizeCol(0)
{
	boardCount++;
}

AbstractBoard::~AbstractBoard()
{
	boardCount--;
}

int AbstractBoard::numberOfBoards()
{
	return boardCount;
}

int AbstractBoard::numberOfMoves()
{
	return moveCount;
}

Direction AbstractBoard::lastMove()
{
	return moveLast;
}

int AbstractBoard::getSizeRow() const
{
	return sizeRow;
}

int AbstractBoard::getSizeCol() const
{
	return sizeCol;
}

bool AbstractBoard::sizeControl(const int& height, const int& width) const
{
	if( height>9 || height<3 || width>9 || width<3 )
		return false;

	else
		return true;
}

bool AbstractBoard::operator ==(const AbstractBoard* other) const
{
	bool control = true;
	
	if( !sizeRow==other->getSizeRow() || !sizeCol==other->getSizeCol() )
		control = false;
	
	for(int i=1; ( i<=sizeRow && control==true ); i++)
	{
		for(int j=1; ( j<=sizeCol && control==true ); j++)
		{
			if( (*this)(i,j) != (*other)(i,j) )
				control = false;
		}
	}

	return control;
}