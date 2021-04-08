#include "ClassDef.h"

const int NPuzzle::Board::border = -1;
const int NPuzzle::Board::empty = 0;

NPuzzle::Board::Board(){/*Intentional*/}

bool NPuzzle::Board::readFromFile(const string& fileName){
	bool control;
	int row, col;
	char cell[2], dummy;

	ifstream file;
	file.open(fileName);
	
	if( file.is_open() ){

		for(row=0; row<11; row++){
			for(col=0; col<11; col++){
				board[row][col] = border;
			}
		}

		for(row=1, dummy='\n'; dummy=='\n'; row++){ //if there is a new line at the end of the line file continues (not end of the file)
			for(col=1, dummy=' '; ( dummy==' ' && !file.eof() ); col++){ //if the dummy character is space it is not end of the line yet
				file.get(cell[0]); //first digit of the cell
				file.get(cell[1]); //second digit
				file.get(dummy); //space / new line

				if( cell[0]=='b' ){ //it is the blank cell
					board[row][col] = empty;
					emptyRow = row;
					emptyCol = col;
				}
				else if( atoi(cell)!=0 ) //if not border
					board[row][col] = atoi(cell);
			}
		}
		sizeRow = row-1;
		sizeCol = col-1;

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

		for(row=1; row<=sizeRow; row++){
			for(col=1; col<=sizeCol; col++){
				
				if( board[row][col]==empty ) //empty cell
					file << "bb";
				else if( board[row][col]==border ) //border
					file << "00";
				else if( (board[row][col]-10) < 0 ) //one digit number
					file << "0" << board[row][col];
				else
					file << board[row][col]; //two digit number
				
				if( col==sizeCol && row!=sizeRow ) //end of line
					file << endl;
				else if( col!=sizeCol ) //not end of file
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

	for(int row=1; row<=sizeRow; row++){
		for(int col=1; col<=sizeCol; col++){

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
	for(int row=1; ( row<=sizeRow && control==true ); row++){
		for(int col=1; ( col<=sizeCol && control==true ); col++){
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
	
	sizeRow = width;
	sizeCol = height;
}

void NPuzzle::Board::reset(){
	int count = 1;

	for(int row=0; row<11; row++){
		for(int col=0; col<11; col++){
				board[row][col] = border;
		}
	}

	for(int row=1; row<=sizeRow; row++){
		for(int col=1; col<=sizeCol; col++, count++){
				board[row][col] = count;
		}
	}

	board[sizeRow][sizeCol] = empty;
	emptyRow = sizeRow;
	emptyCol = sizeCol;
}

bool NPuzzle::Board::moveControl(Direction direc) const{
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
}

int NPuzzle::Board::calcHeuristic(){
	int heuristic = 0;
	int currRow, currCol;

	for(int row=1; row<=sizeRow; row++){
		for(int col=1; col<=sizeCol; col++){

			if( board[row][col]!=empty && board[row][col]!=border ){
				currRow = row;
				currCol = col;

				heuristic += calcDisstanceToFinalPos(currRow,currCol); //calulates the move count to get to the final position
			}
		}
	}

	return heuristic;
}

int NPuzzle::Board::calcDisstanceToFinalPos(int currRow, int currCol){
	int count = 0;
	bool posFound = false;
	int row, col, finalRow, finalCol;

	int disstance = 0;
	int difference;

//finding the final position of the cell that we are currently at
	row=0;//Starting from 0 because row will be incremented at the start. It will start from 1
	while( row<=sizeRow && posFound==false ){
		row++; //Incrementing at the start because I dont want the position to be incremented after the position is found

		col=0;
		while( col<=sizeCol && posFound==false ){
			col++;
		//counting from the start of the baoard to calculate the fianl position
			if( board[row][col] != border ){
				count++;
			//final position found
				if( board[ currRow ][ currCol ] == count )
					posFound = true;
			}
		}
	}
	finalRow = row;
	finalCol = col;


//calculating the distance between current position and final position
	difference = currRow - finalRow; 
	if( difference<0 )
		difference = -difference;
	disstance += difference;

	difference = currCol - finalCol;
	if( difference<0 )
		difference = -difference;
	disstance += difference;

	return disstance;
}