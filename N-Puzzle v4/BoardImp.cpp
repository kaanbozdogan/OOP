#include "ClassDef.h"

const int NPuzzle::Board::border = -1;
const int NPuzzle::Board::empty = 0;
int NPuzzle::Board::boardCount = 0;

NPuzzle::Board::Board(){
	boardCount++;
	moveCount = 0;
	lastMove = None;
}

NPuzzle::Board::Board(vector< vector<int> > vector, int eRow, int eCol){
	board = vector;
	emptyRow = eRow;
	emptyCol = eCol;

	boardCount++;
	moveCount = 0;
	lastMove = None;
}

bool NPuzzle::Board::readFromFile(const string& fileName){
	bool control;
	int row, col;
	char cell[2], dummy;

	vector<int> oneRowOfBoard;

	ifstream file;
	file.open(fileName);
	
	if( file.is_open() ){

		for(row=0; row<11; row++){
			oneRowOfBoard.push_back(border);
		}
		board.push_back(oneRowOfBoard);
		oneRowOfBoard.clear();

		for(row=1, dummy='\n'; dummy=='\n'; row++){ //if there is a new line at the end of the line file continues (not end of the file)
			
			oneRowOfBoard.push_back(border);
			for(col=1, dummy=' '; ( dummy==' ' && !file.eof() ); col++){ //if the dummy character is space it is not end of the line yet
				file.get(cell[0]); //first digit of the cell
				file.get(cell[1]); //second digit
				file.get(dummy); //space / new line

				if( cell[0]=='b' ){ //it is the blank cell
					oneRowOfBoard.push_back(empty);
					emptyRow = row;
					emptyCol = col;
				}
				else if( atoi(cell)!=0 ) //if not border
					oneRowOfBoard.push_back( atoi(cell) );
				else
					oneRowOfBoard.push_back(border);
			}
			oneRowOfBoard.push_back(border);

			board.push_back(oneRowOfBoard);
			oneRowOfBoard.clear();
		}

		for(row=0; row<11; row++){
			oneRowOfBoard.push_back(border);
		}
		board.push_back(oneRowOfBoard);

		moveCount = 0;
		lastMove = None;

		file.close();
		control = true;
	}
	else
		control = false;

	return control;
}

bool NPuzzle::Board::writeToFile(const string& fileName) const{
	int row, col;
	bool control;

	ofstream file;
	file.open(fileName);

	if( file.is_open() ){

		for(row=1; row<board.size()-1; row++){
			for(col=1; col<board[row].size()-1; col++){
				
				if( board[row][col]==empty ) //empty cell
					file << "bb";
				else if( board[row][col]==border ) //border
					file << "00";
				else if( (board[row][col]-10) < 0 ) //one digit number
					file << "0" << board[row][col];
				else
					file << board[row][col]; //two digit number
				
				if( col==board[row].size()-1 && row!=board.size()-1 ) //end of line
					file << endl;
				else if( col!=board[row].size()-1 ) //not end of file
					file << " ";
			}
		}
		control = true;
	}
	else
		control = false;

	file.close();

	return control;
}

void NPuzzle::Board::print() const{

	for(int row=1; row<board.size()-1; row++){
		for(int col=1; col<board[row].size()-1; col++){

			if( board[row][col]==border )
				cout << "00\t" ;
			else if( board[row][col]==empty )
				cout << "bb\t" ;
			else
				cout << board[row][col] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

bool NPuzzle::Board::isSolved() const{
	bool control = true;
	int count = 0;

//Controlling if the cells are ordered
	for(int row=1; ( row<board.size()-1 && control==true ); row++){
		for(int col=1; ( col<board[row].size()-1 && control==true ); col++){
			if( board[row][col]!=border ){
				count ++;
				if( board[row][col]!=count && board[row][col]!=empty )
					control = false;
			}
		}
	}

	return control;
}

void NPuzzle::Board::setSize(const int& height, const int& width){
	
	board.resize(height+2);
	for(int row=0; row<board.size(); row++){
		board[row].resize(width+2);
	}
}

void NPuzzle::Board::reset(){
	int count = 1;

	for(int row=0; row<board.size(); row++){
		for(int col=0; col<board[row].size(); col++){
				board[row][col] = border;
		}
	}

	for(int row=1; row<board.size()-1; row++){
		for(int col=1; col<board[row].size()-1; col++, count++){
				board[row][col] = count;
		}
	}

	board[ board.size()-2 ][ board[ getSizeRow() ].size()-2 ] = empty;
	emptyRow = board.size()-2;
	emptyCol = board[ getSizeRow() ].size()-2;

	moveCount = 0;
	lastMove = None;	
}

bool NPuzzle::Board::moveControl(const Direction& direc) const{
	bool control = false;

//Controls if there is a border in the moving direciton
	switch(direc){
		case Up:
			if( board[ emptyRow-1 ][ emptyCol ] !=border )
				control = true;
			break;
		case Down:
			if( board[ emptyRow+1 ][ emptyCol ] !=border )
				control = true;
			break;
		case Left:
			if( board[ emptyRow ][ emptyCol-1 ] !=border )
				control = true;
			break;
		case Right:
			if( board[ emptyRow ][ emptyCol+1 ] !=border )
				control = true;
			break;
	}

	return control;
}

void NPuzzle::Board::move(const Direction& dir){
	int temp;

	switch(dir){
		case Up:
			temp = board[ emptyRow-1 ][ emptyCol ];			
			board[ emptyRow-1 ][ emptyCol ] = empty;
			board[ emptyRow ][ emptyCol ] = temp;
			
			emptyRow = emptyRow - 1;
			break;

		case Down:
			temp = board[ emptyRow+1 ][ emptyCol ];			
			board[ emptyRow+1 ][ emptyCol ] = empty;
			board[ emptyRow ][ emptyCol ] = temp;
			
			emptyRow = emptyRow + 1;
			break;

		case Left:
			temp = board[ emptyRow ][ emptyCol-1 ];			
			board[ emptyRow ][ emptyCol-1 ] = empty;
			board[ emptyRow ][ emptyCol ] = temp;
			
			emptyCol = emptyCol - 1;
			break;

		case Right:
			temp = board[ emptyRow ][ emptyCol+1 ];			
			board[ emptyRow ][ emptyCol+1 ] = empty;
			board[ emptyRow ][ emptyCol ] = temp;
			
			emptyCol = emptyCol + 1;
			break;
	}

	moveCount++;
	lastMove = dir;
}
