#include "BoardArray1D.h"

BoardArray1D::BoardArray1D() : AbstractBoard(), size(0)
{/*Intentionaly left blank*/}

BoardArray1D::BoardArray1D(const int& height, const int& width) : AbstractBoard(), size(0)
{
	setSize(height,width);
}

BoardArray1D::~BoardArray1D()
{
	if( size!=0 )
		delete board;
}

BoardArray1D::BoardArray1D(const BoardArray1D& other) : AbstractBoard()
{
	sizeRow = other.sizeRow;
	sizeCol = other.sizeCol;

	emptyRow = other.emptyRow;
	emptyCol = other.emptyCol;

	size = sizeRow * sizeCol;

	board = new int[size];

	for(int i=0; i<size; i++)
		board[i] = other.board[i];
}

BoardArray1D& BoardArray1D::operator =(const BoardArray1D& other)
{	
	//If the size is not equal, we need to reallocate
	if( size!=other.size )
	{	
		//If there is size allocated already, we need to delete it
		if( size!=0 )
			delete[] board;

		sizeRow = other.sizeRow;
		sizeCol = other.sizeCol;
		size = sizeRow * sizeCol;

		board = new int[size];
	}

	for(int i=0; i<size; i++)
		board[i] = other.board[i];

	emptyRow = other.emptyRow;
	emptyCol = other.emptyCol;

	return *this;
}

void BoardArray1D::print() const
{
	for(int i=0; i<size; i++)
	{
		if( board[i]==border )
			cout << "00\t" ;
		else if( board[i]==empty )
			cout << "  \t" ;
		else
			cout << board[i] << "\t";
		
		if( (i+1)%sizeCol == 0 )
			cout << endl;
	}

	cout << endl;
}

bool BoardArray1D::writeToFile(const string& fileName) const
{
	bool control;

	ofstream file;
	file.open(fileName);

	if( file.is_open() ){

		for(int i=0; i<size; i++)
		{				
				if( board[i]==empty ) //empty cell
					file << "bb";
				else if( board[i]==border ) //border
					file << "00";
				else if( (board[i]-10) < 0 ) //one digit number
					file << "0" << board[i];
				else
					file << board[i]; //two digit number

				if( (i+1)%sizeCol != 0 ) //not end of line
					file << " ";
				else if( i+1 != size ) //end of line but not end of file
					file << endl;
		}
		control = true;
	}
	else
		control = false;

	file.close();

	return control;
}

bool BoardArray1D::readFromFile(const string& fileName)
{
	int tempBoard[81];

	bool control;
	int row, col, i;
	char cell[2], dummy;

	ifstream file;
	file.open(fileName);
	
	if( file.is_open() ){

		for(i=0, row=0, dummy='\n'; dummy=='\n'; row++) //if there is a new line at the end of the line file continues (not end of the file)
		{
			for(col=0, dummy=' '; ( dummy==' ' && !file.eof() ); i++, col++) //if the dummy character is space it is not end of the line yet
			{
				file.get(cell[0]); //first digit of the cell
				file.get(cell[1]); //second digit
				file.get(dummy); //space / new line

				if( cell[0]=='b' ) //it is the blank cell
				{
					tempBoard[i] = empty;
					emptyRow = row;
					emptyCol = col;
				}
				else if( atoi(cell)!=0 ) //if not border
					tempBoard[i] = atoi(cell);

				else
					tempBoard[i] = border;
			}
		}

		sizeRow = row;
		sizeCol = col;
		size = sizeRow * sizeCol;

		board = new int[size];

		for(i=0; i<size; i++)
			board[i] = tempBoard[i];

		moveCount = 0;
		moveLast = None;

		file.close();
		control = true;
	}
	else
		control = false;

	return control;
}

bool BoardArray1D::setSize(const int& height, const int& width)
{
	bool control;

	if( sizeControl(height,width) )
	{
		//If the board already has size, we need to delete the allocated space
		if( size!=0 )
		{
			delete[] board;
		}

		sizeRow = height;
		sizeCol = width;
		size = height * width;

		board = new int[size];
	
		reset();

		control = true;
	}
	else
		control = false;

	return control;
}

void BoardArray1D::reset()
{
	for(int i=0; i<size; i++)
		board[i] = i + 1;

	board[size-1] = empty;
	emptyRow = sizeRow-1;
	emptyCol = sizeCol-1;

	moveCount = 0;
	moveLast = None;

}

bool BoardArray1D::move(const Direction& direc)
{
	bool control;
	int temp, emptyIndex, movedIndex;

	if( moveControl(direc) )
	{
		emptyIndex = getIndexOfCoordinate(emptyRow,emptyCol);

		//Updating the coordinates of empty cell
		switch(direc)
		{
			case Up:
				emptyRow--;
				break;
			case Down:
				emptyRow++;
				break;
			case Left:
				emptyCol--;
				break;
			case Right:
				emptyCol++;
				break;
		}

		movedIndex = getIndexOfCoordinate(emptyRow,emptyCol);

		temp = board[movedIndex];
		board[movedIndex] = empty;
		board[emptyIndex] = temp;
	
		moveCount++;
		moveLast = direc;
		control = true;
	}
	else
		control = false;

	return control;
}

bool BoardArray1D::isSolved() const
{
	bool control = true;

	for(int i=0; ( i<size-1 && control==true ); i++)
	{
		if( board[i] != i+1 )
			control = false;
	}

	if( board[size-1]!=empty )
		control = false;

	return control;
}

int BoardArray1D::operator ()(const int& row, const int& col) const
{
	if( size>0 )
	{
		if( row<1 || col<1 || row>sizeRow || col>sizeCol )
		{
			cout << endl << "BoardArray1D::operator() trying to reach invalid index!!! Program exits." << endl;
			exit(1);
		}
		else
			return board[ getIndexOfCoordinate(row-1,col-1) ];
	}
}

bool BoardArray1D::moveControl(const Direction& direc) const
{
	bool control = false;
	int movedRow, movedCol, movedIndex;

//Moved coordinates are determined, then controls if the move is not out of board
	switch(direc)
	{
		case Up:
			movedRow = emptyRow - 1;
			movedCol = emptyCol;

			if( movedRow >= 0 )
				control = true;
			break;

		case Down:
			movedRow = emptyRow + 1;
			movedCol = emptyCol;

			if( movedRow <= sizeRow-1 )
				control = true;
			break;

		case Left:
			movedRow = emptyRow;
			movedCol = emptyCol - 1;

			if( movedCol >= 0 )
				control = true;
			break;

		case Right:
			movedRow = emptyRow;
			movedCol = emptyCol + 1;

			if( movedCol <= sizeCol-1 )
				control = true;
			break;
	}

//Controls if the moved cell is a border
	if( control==true )
	{
		movedIndex = getIndexOfCoordinate(movedRow,movedCol);

		if( board[movedIndex]==border )
			control = false;
	}

	return control;
}

int BoardArray1D::getSize() const
{
	return sizeRow * sizeCol;
}

int BoardArray1D::getIndexOfCoordinate(const int& y, const int& x) const
{
	return y * sizeCol + x;
}