#include "BoardArray2D.h"

BoardArray2D::BoardArray2D() : AbstractBoard()
{/*Intentionaly left blank*/}

BoardArray2D::BoardArray2D(const int& height, const int& width) : AbstractBoard()
{
	setSize(height,width);
}

BoardArray2D::~BoardArray2D()
{
	if( sizeRow!=0 )
	{
		for(int i=0; i<sizeRow; i++)
		{
			delete[] board[i];
		}
		delete[] board;
	}
}

BoardArray2D::BoardArray2D(const BoardArray2D& other) : AbstractBoard()
{
	sizeRow = other.sizeRow;
	sizeCol = other.sizeCol;

	emptyRow = other.emptyRow;
	emptyCol = other.emptyCol;

	board = new int*[sizeRow];

	for(int i=0; i<sizeRow; i++)
	{
		board[i] = new int[sizeCol];
	}

	for(int i=0; i<sizeRow; i++)
	{
		for(int j=0; j<sizeCol; j++)
		{
			board[i][j] = other.board[i][j];
		}
	}	
}

BoardArray2D& BoardArray2D::operator =(const BoardArray2D& other)
{	
	//If board already has size, we might need to delete some space
	if( sizeRow!=0 )
	{
		//If row count is not equal
		if( sizeRow!=other.sizeRow )
		{
			for(int i=0; i<sizeRow; i++)
				delete[] board[i];
			delete[] board;
	
			sizeRow = other.sizeRow;
		
			//If column count is not equal
			if( sizeCol!=sizeRow )
				sizeCol = other.sizeCol;
	
			board = new int*[sizeRow];
			for(int i=0; i<sizeRow; i++)
				board[i] = new int[sizeCol];
	
		}
		//If row count is equal but column count is not
		else if( sizeCol!=other.sizeCol )
		{	
			sizeCol = other.sizeCol;
	
			for(int i=0; i<sizeRow; i++)
			{
				delete[] board[i];
				board[i] = new int[sizeCol];
			}
		}
	}
	//If board has no size, no need to delete
	else
	{
		sizeRow = other.sizeRow;
		sizeCol = other.sizeCol;

		board = new int*[sizeRow];
		for(int i=0; i<sizeRow; i++)
			board[i] = new int[sizeCol];
	}
	//After making sizes equal copy boards
	for(int i=0; i<sizeRow; i++)
	{
		for(int j=0; j<sizeCol; j++)
		{
			board[i][j] = other.board[i][j];
		}
	}

	return *this;
}

void BoardArray2D::print() const
{
	for(int row=0; row<sizeRow; row++){
		for(int col=0; col<sizeCol; col++){

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

bool BoardArray2D::writeToFile(const string& fileName) const
{
	bool control;

	ofstream file;
	file.open(fileName);

	if( file.is_open() ){

		for(int row=0; row<sizeRow; row++){
			for(int col=0; col<sizeCol; col++){
				
				if( board[row][col]==empty ) //empty cell
					file << "bb";
				else if( board[row][col]==border ) //border
					file << "00";
				else if( (board[row][col]-10) < 0 ) //one digit number
					file << "0" << board[row][col];
				else
					file << board[row][col]; //two digit number

				if( col!=sizeCol-1 ) //not end of line
					file << " ";
				else if( row!=sizeRow-1 ) //end of line but not end of file
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

bool BoardArray2D::readFromFile(const string& fileName)
{
	int boardTemp[9][9];

	bool control;
	int row, col;
	char cell[2], dummy;

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
					boardTemp[row][col] = empty;
					emptyRow = row;
					emptyCol = col;
				}
				else if( atoi(cell)!=0 ) //if not border
					boardTemp[row][col] = atoi(cell) ;

				else
					boardTemp[row][col] = border;
			}
		}

		sizeRow = row;
		sizeCol = col;

		board = new int*[row];

		for(int i=0; i<sizeRow; i++)
		{
			for(int j=0; j<sizeCol; j++)
				board[i] = new int[col];
		}

		for(int i=0; i<sizeRow; i++)
		{
			for(int j=0; j<sizeCol; j++)
				board[i][j] = boardTemp[i][j];
		}

		moveCount = 0;
		moveLast = None;

		file.close();
		control = true;
	}
	else
		control = false;

	return control;
}

bool BoardArray2D::setSize(const int& height, const int& width)
{
	bool control;

	if( sizeControl(height,width) )
	{	
		//If the board already has size, we need to delete the allocated space
		if( sizeRow!=0 )
		{
			for(int i=0; i<sizeRow; i++)
				delete[] board[i];

			delete[] board;
		}

		sizeRow = height;
		sizeCol = width;

		board = new int*[height];
		
		for(int i=0; i<height; i++)
			board[i] = new int[width];

		reset();

		control = true;
	}
	else
		control = false;

	return control;
}

void BoardArray2D::reset()
{
	int count = 1;

	for(int row=0; row<sizeRow; row++){
		for(int col=0; col<sizeCol; col++, count++){
				board[row][col] = count;
		}
	}

	board[sizeRow-1][sizeCol-1] = empty;
	emptyRow = sizeRow-1;
	emptyCol = sizeCol-1;

	moveCount = 0;
	moveLast = None;
}

bool BoardArray2D::move(const Direction& direc)
{
	bool control;
	int temp, movedRow, movedCol;

	if( moveControl(direc) )
	{
		movedCol = emptyCol;
		movedRow = emptyRow;
		
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

bool BoardArray2D::isSolved() const
{
	bool control = true;
	int count = 0;
//Controlling if the cells are ordered
	if( sizeRow!=0 )
	{	
		for(int row=0; ( row<sizeRow && control==true ); row++)
		{
			for(int col=0; ( col<sizeCol && control==true ); col++)
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
	else
		control = false;

	return control;
}

int BoardArray2D::operator ()(const int& row, const int& col) const
{
	if( sizeRow>0 && sizeCol>0 )
	{
		if( row<1 || col<1 || row>sizeRow || col>sizeCol )
		{
			cout << endl << "BoardArray2D::operator() trying to reach invalid index!!! Program exits." << endl;
			exit(1);
		}
		else
			return board[row-1][col-1];
	}
}

bool BoardArray2D::moveControl(const Direction& direc) const
{
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

//Controls if the moved cell is a border if its a moveable cell
	if( control ){
		if( board[movedRow][movedCol] == border )
			control = false;
	}

	return control;
}