#include "FirstHW.h"


int getSize(){
	int size;

	cout << "Please enter the problem size: ";
	cin >> size;

	while( size<3 || size>9 ){
		cout << endl << "Problem size can be between 3 and 9 please try again: ";
		cin >> size;
	}

	return size;
}


void initBoard(int board[][11], int emptyCell[2], int size[2]){
	int row, col;

	for(row=0; row<11; row++){
		for(col=0; col<11; col++){
				board[row][col] = border;
		}
	}

	for(row=1; row<=size[0]; row++){
		for(col=1; col<=size[1]; col++){
				board[row][col] = (row-1)*size[0] + col;
		}
	}

	board[size[0]][size[1]] = empty;
	emptyCell[0] = size[0];
	emptyCell[1] = size[1];
}


void shuffle(int board[][11], int emptyCell[2], int size[2]){
	for(int i=0; i<size[0]*size[1]; i++){
		randomMove(board,emptyCell);
	}
}


bool moveControl(int board[][11], int emptyCell[2], Direction direc){
	bool control = false;

//Controls if there is a border in the moving direciton
	switch(direc){
		case Up:
			if( board[ emptyCell[0]-1 ][ emptyCell[1] ] !=border )
				control = true;
			break;
		case Down:
			if( board[ emptyCell[0]+1 ][ emptyCell[1] ] !=border )
				control = true;
			break;
		case Left:
			if( board[ emptyCell[0] ][ emptyCell[1]-1 ] !=border )
				control = true;
			break;
		case Right:
			if( board[ emptyCell[0] ][ emptyCell[1]+1 ] !=border )
				control = true;
			break;
	}

	return control;
}


void randomMove(int board[][11], int emptyCell[2]){
	Direction direc;

//Loops until it finds the valid direction
	do{
		direc = static_cast<Direction>( rand()%4 );	
	}while( !moveControl(board,emptyCell,direc) );

//making the valid move
	updateBoard(board,emptyCell,direc);	
}


void updateBoard(int board[][11], int emptyCell[2], Direction direc){
	int temp;

	switch(direc){
		case Up:
			temp = board[ emptyCell[0]-1 ][ emptyCell[1] ];			
			board[ emptyCell[0]-1 ][ emptyCell[1] ] = empty;
			board[ emptyCell[0] ][ emptyCell[1] ] = temp;
			
			emptyCell[0] = emptyCell[0] - 1;
			break;

		case Down:
			temp = board[ emptyCell[0]+1 ][ emptyCell[1] ];			
			board[ emptyCell[0]+1 ][ emptyCell[1] ] = empty;
			board[ emptyCell[0] ][ emptyCell[1] ] = temp;
			
			emptyCell[0] = emptyCell[0] + 1;
			break;

		case Left:
			temp = board[ emptyCell[0] ][ emptyCell[1]-1 ];			
			board[ emptyCell[0] ][ emptyCell[1]-1 ] = empty;
			board[ emptyCell[0] ][ emptyCell[1] ] = temp;
			
			emptyCell[1] = emptyCell[1] - 1;
			break;

		case Right:
			temp = board[ emptyCell[0] ][ emptyCell[1]+1 ];			
			board[ emptyCell[0] ][ emptyCell[1]+1 ] = empty;
			board[ emptyCell[0] ][ emptyCell[1] ] = temp;
			
			emptyCell[1] = emptyCell[1] + 1;
			break;
	}
}


void assignBoard(int board[][11], int emptyCell[2], int boardTemp[][11], int emptyCellTemp[2]){
	int row, col;

	for(row=0; row<11; row++){
		for(col=0; col<11; col++){		
			boardTemp[row][col] = board[row][col];
		}
	}

	emptyCellTemp[0] = emptyCell[0];
	emptyCellTemp[1] = emptyCell[1];
}


void printBoard(int board[][11], int size[2]){
	int row, col;

	for(row=1; row<=size[0]; row++){
		for(col=1; col<=size[1]; col++){

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


void printControlInf(){
	cout << "V: Tries to solve the puzzle with intelligent algorithm" << endl
	<< "T: print report" << endl
	<< "E: saves the puzzle configuration to a file" << endl
	<< "L: loads the puzzle configuration from a file" << endl << endl;
}


bool isFinished(int board[][11], int size[2]){
	bool control = true;
	int count = 0;

//Controlling if the cells are ordered
	for(int row=1; ( row<=size[0] && control==true ); row++){
		for(int col=1; ( col<=size[1] && control==true ); col++){
			if( board[row][col]!=border ){
				count ++;
				if( board[row][col]!=count && board[row][col]!=empty )
					control = false;
			}
		}
	}

	return control;
}