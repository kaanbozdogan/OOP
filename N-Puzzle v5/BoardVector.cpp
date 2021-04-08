#include "BoardVector.h"

BoardVector::BoardVector() : AbstractBoard()
{/*Intentionaly left blank*/}

BoardVector::BoardVector(const int& height, const int& width) : AbstractBoard()
{
	setSize(height,width);
}

BoardVector::BoardVector(const BoardVector& other) : AbstractBoard()
{
	sizeRow = other.sizeRow;
	sizeCol = other.sizeCol;

	emptyRow = other.emptyRow;
	emptyCol = other.emptyCol;

	vector<int> oneLineOfBoard;

	for(int i=0; i<other.board.size(); i++)
	{
		for(int j=0; j<other.board[i].size(); j++)
			oneLineOfBoard.push_back( other.board[i][j] );

		board.push_back(oneLineOfBoard);
		oneLineOfBoard.clear();
	}
}

BoardVector::~BoardVector()
{/*intentional*/}

void BoardVector::print() const
{
	for(int row=0; row<board.size(); row++)
	{
		for(int col=0; col<board[row].size(); col++)
		{
			if( board[row][col]==border )
				cout << "00\t" ;
			else if( board[row][col]==empty )
				cout << "  \t" ;
			else
				cout << board[row][col] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

bool BoardVector::writeToFile(const string& fileName) const
{
	bool control;

	ofstream file;
	file.open(fileName);

	if( file.is_open() ){

		for(int row=0; row<board.size(); row++){
			for(int col=0; col<board[row].size(); col++){
				
				if( board[row][col]==empty ) //empty cell
					file << "bb";

				else if( board[row][col]==border ) //border
					file << "00";

				else if( (board[row][col]-10) < 0 ) //one digit number
					file << "0" << board[row][col];

				else
					file << board[row][col]; //two digit number


				if( col!=board[row].size()-1 ) //not end of line
					file << " ";

				else if( row!=board.size()-1 ) //end of line but not end of file
					file << endl;
			}
		}
		control = true;
	}
	else
		control = false;

	file.close();

	return control;
}

bool BoardVector::readFromFile(const string& fileName)
{
	bool control;
	int row, col;
	char cell[2], dummy;

	vector< vector<int> > newBoard;
	vector<int> oneRowOfBoard;

	ifstream file;
	file.open(fileName);
	
	if( file.is_open() ){

		for(row=0, dummy='\n'; dummy=='\n'; row++) //if there is a new line at the end of the line file continues (not end of the file)
		{
			for(col=0, dummy=' '; ( dummy==' ' && !file.eof() ); col++) //if the dummy character is space it is not end of the line yet
			{
				file.get(cell[0]); //first digit of the cell
				file.get(cell[1]); //second digit
				file.get(dummy); //space / new line

				if( cell[0]=='b' ) //it is the blank cell
				{
					oneRowOfBoard.push_back(empty);
					emptyRow = row;
					emptyCol = col;
				}
				else if( atoi(cell)!=0 ) //if not border
					oneRowOfBoard.push_back( atoi(cell) );

				else
					oneRowOfBoard.push_back(border);
			}

			newBoard.push_back(oneRowOfBoard);
			oneRowOfBoard.clear();
		}

		board = newBoard;
		sizeRow = board.size();
		sizeCol = board[0].size();
		moveCount = 0;
		moveLast = None;

		file.close();
		control = true;
	}
	else
		control = false;

	return control;
}

bool BoardVector::setSize(const int& height, const int& width)
{
	bool control;

	if( sizeControl(height,width) )
	{
		sizeRow = height;
		sizeCol = width;

		board.resize(sizeRow);

		for(int row=0; row<board.size(); row++)
		{
			board[row].resize(sizeCol);
		}
		reset();

		control = true;
	}
	else
		control = false;

	return control;
}

void BoardVector::reset()
{
	int count = 1;

	for(int row=0; row<board.size(); row++)
	{
		for(int col=0; col<board[row].size(); col++, count++)
		{
			board[row][col] = count;
		}
	}

	board[board.size()-1][board[0].size()-1] = empty;
	emptyRow = board.size()-1;
	emptyCol = board[0].size()-1;

	moveCount = 0;
	moveLast = None;
}

bool BoardVector::move(const Direction& direc)
{
	bool control;
	int temp, movedRow, movedCol;

	if( moveControl(direc) )
	{
		movedCol = emptyCol;
		movedRow = emptyRow;
	
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

		temp = board[ emptyRow ][ emptyCol ];			
		board[ emptyRow ][ emptyCol ] = empty;
		board[ movedRow ][ movedCol ] = temp;
	
		moveCount++;
		moveLast = direc;
		control = true;
	}
	else
		control = false;

	return control;
}

bool BoardVector::isSolved() const
{
	bool control = true;
	int count = 0;
//Controlling if the cells are ordered
	if( sizeRow!=0 )
	{
		for(int row=0; ( row<board.size() && control==true ); row++)
		{
			for(int col=0; ( col<board[row].size() && control==true ); col++)
			{
				if( board[row][col]!=border )
				{
					count ++;
					if( board[row][col]!=count && board[row][col]!=empty )
						control = false;
				}
			}
		}
	}
	
	return control;
}

int BoardVector::operator ()(const int& row, const int& col) const
{
	if( row<1 || col<1 || row>sizeRow || col>sizeCol )
	{
		cout << endl << "BoardVector::operator() trying to reach invalid index!!! Program exits." << endl;
		exit(1);
	}
	else
		return board[row-1][col-1];
}

bool BoardVector::moveControl(const Direction& direc) const{
	bool control = false;
	int movedRow, movedCol;

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

			if( movedRow <= board.size()-1 )
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

			if( movedCol <= board[emptyRow].size()-1 )
				control = true;
			break;
	}

//Controls if the moved cell is a border if its a moveable cell
	if( control ){
		if( board[movedRow][movedCol] == border )
			control = false;
	}

	return control;
}