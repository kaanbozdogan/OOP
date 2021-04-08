#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

enum Direction {Up, Down, Left, Right, None};

const int border = -1;
const int empty = 0;


int getSize();
void initBoard(int board[][11], int emptyCell[2], int size);
void printBoard(int board[][11]);
void printControlInf();

int menu(int board[][11], int emptyCell[2], int size);

bool moveControl(int board[][11], int emptyCell[2], Direction direc); //Controls if move is valid
void updateBoard(int board[][11], int emptyCell[2], Direction direc); //Updates the board with moving the empty cell

void shuffle(int board[][11], int emptyCell[2], int size); //shuffles size*size times
void randomMove(int board[][11], int emptyCell[2]);

Direction intelligentMove(int board[][11], int emptyCell[2], int size, Direction lastIntelligentMove);
void assignBoard(int board[][11], int emptyCell[2], int boardTemp[][11], int emptyCellTemp[2]); //copies board to boardTemp
int calcHeuristic(int board[][11], int size); //calclates how close the board is to the finishing position
int compareHeuristic(int heuristics[4]); //Chooses the closest one to the final position

bool isFinished(int board[][11], int size);

/*--------------------------------------------------*/

int main(){
	srand(time(NULL));

	int size;
	int board[11][11];
	int emptyCell[2]; //Empty cell coordinates. Don't want to search it every time.

	size = getSize();

	initBoard(board,emptyCell,size);

	shuffle(board,emptyCell,size);

	menu(board,emptyCell,size);

	return 0;
}

/*--------------------------------------------------*/

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

void initBoard(int board[][11], int emptyCell[2], int size){
	int row, col;

	for(row=0; row<11; row++){
		for(col=0; col<11; col++){
				board[row][col] = border;
		}
	}

	for(row=1; row<=size; row++){
		for(col=1; col<=size; col++){
				board[row][col] = (row-1)*size + col;
		}
	}

	board[size][size] = empty;
	emptyCell[0] = size;
	emptyCell[1] = size;
}

void printBoard(int board[][11]){
	int row, col;

	for(row=1, col=1; board[row][col]!=border; row++){
		for(col=1; board[row][col]!=border; col++){
			
			if( board[row][col]==empty )
				cout << "_    ";
			else
				cout << board[row][col] << "    ";
		}
		cout << endl;
		col = 1;
	}
	cout << endl;
}

void printControlInf(){
	cout << "L: moves the empty cell left if there is room" << endl
	<< "R: moves the empty cell right if there is room" << endl
	<< "U: moves the empty cell up if there is room" << endl
	<< "D: moves the empty cell down if there is room" << endl
	<< "I: makes an “intelligent” move for you." << endl
	<< "S: shuffles the board" << endl
	<< "Q: quit" << endl << endl;
}

int menu(int board[][11], int emptyCell[2], int size){
	char move;
	Direction direc;
	Direction lastIntelligentMove = None;
	Direction forbiddentIntelligentMove = None;
	Direction temp;
	
	int moveCount = 0;
	bool quit = false;
	bool invalid = false;
	bool finish = false;

	printControlInf();
	printBoard(board);

	do{	
		cout << "Your move: ";
		cin >> move;

		while( move!='U' && move!='D' && move!='L' && move!='R' && move!='I' && move!='S' && move!='Q'){
			cout << endl << "Choose a valid input: ";
			cin >> move;
		}

		switch( move ){
			case 'U':
				direc = Up;
				if( moveControl(board,emptyCell,direc) )
					updateBoard(board,emptyCell,direc);
				else
					bool invalid = true;
				break;

			case 'D':
				direc = Down;
				if( moveControl(board,emptyCell,direc) )
					updateBoard(board,emptyCell,direc);
				else
					bool invalid = true;
				break;

			case 'L':
				direc = Left;
				if( moveControl(board,emptyCell,direc) )
					updateBoard(board,emptyCell,direc);
				else
					bool invalid = true;
				break;

			case 'R':
				direc = Right;
				if( moveControl(board,emptyCell,direc) )
					updateBoard(board,emptyCell,direc);
				else
					bool invalid = true;
				break;

			case 'I':
				temp = lastIntelligentMove;
				lastIntelligentMove = intelligentMove(board,emptyCell,size,forbiddentIntelligentMove);
				forbiddentIntelligentMove = temp;
				break;

			case 'S':
				cout << endl << "Shuffling..." << endl;
				shuffle(board,emptyCell,size);
				break;

			case 'Q':
				quit = true;
				break;
		}

		finish = isFinished(board,size);
		printBoard(board);

		if( finish )
			cout << "Problem solved!" << endl<< "Total number of moves: " << moveCount << endl;

		else if( quit )
			cout << "Quiting game..." << endl;

		else if( invalid ){
			cout << "Invalid direction." << endl;
			invalid = false;
		}
		else
			moveCount++;

	}while( quit==false && finish==false );

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

void shuffle(int board[][11], int emptyCell[2], int size){
	for(int i=0; i<size*size; i++){
		randomMove(board,emptyCell);
	}
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

Direction intelligentMove(int board[][11], int emptyCell[2], int size, Direction forbiddentIntelligentMove){
	Direction direc;
	int boardTemp[11][11], emptyCellTemp[2];
	bool direcControls[4];
	int heuristics[4];

//Controls wich directions are valid to move
	for(int i=0; i<4; i++){
		direc = static_cast<Direction>(i);
		direcControls[i] = moveControl(board,emptyCell,direc);
	}
//negating intelligent move to make the previous intelligent move again. Prevents loops.
	direcControls[ static_cast<int>(forbiddentIntelligentMove) ] = false;

	for(int i=0; i<4; i++){
		direc = static_cast<Direction>(i);

	//If the direction is valid then it calculates it's heuristics
		if( direcControls[i] ){
			assignBoard(board,emptyCell,boardTemp,emptyCellTemp);
			updateBoard(boardTemp,emptyCellTemp,direc);
			heuristics[i] = calcHeuristic(boardTemp,size);
		}
		else
			heuristics[i] = 2000; //a heuristic value can never be as much as 2000 in max 9x9 boards
	}

//If heuristic of possibilities are the same make a random move		
	if( compareHeuristic(heuristics)==4 ){
		do{
			direc = static_cast<Direction>( rand()%4 );
		}while( !moveControl(board,emptyCell,direc) );
	}
//Does the move with the samallest heurisrics
	else	
		direc = static_cast<Direction>( compareHeuristic(heuristics) );

	cout << endl << "Intelligent move chooses ";
	switch( direc ){
		case Up:
			cout << "U" << endl;
			break;
		case Down:
			cout << "D" << endl;
			break;
		case Left:
			cout << "L" << endl;
			break;
		case Right:
			cout << "R" << endl;	
			break;
	}

//The board is updated acording to intelligent move
	updateBoard(board,emptyCell,direc);

	return direc;
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

int calcHeuristic(int board[][11], int size){
	int row, col, targetRow, targetCol, difference;
	int heuristic = 0;

//Heuristic: Sum of moves that are needed to make to get every cell into their final position
	for(row=1, col=1; board[row][col]!=border; row++){
		for(col=1; board[row][col]!=border; col++){
			
			if( board[row][col]!=empty ){ //Not considering empty cell's heuristic value
			
				targetRow = (board[row][col]-1) / size + 1;
				targetCol = board[row][col] % size;
				if( targetCol==0 )
					targetCol = size;

				difference = row - targetRow;
				if( difference<0 ) //Not sure if I can use abs() in hw so not taking risks about it
					difference = -difference;
				heuristic += difference;

				difference = col - targetCol;
				if( difference<0 )
					difference = -difference;
				heuristic += difference;
			}
		}
		col = 1;
	}

	return heuristic;
}

int compareHeuristic(int heuristics[4]){
	int smallest = 0;

	for(int i=1; i<4; i++){
		if( heuristics[i] < heuristics[smallest] )
			smallest = i;
	}

//Controlling if there is multiples from the smallest heuristic
	for(int i=0; i<4; i++){
		if( heuristics[i]==heuristics[smallest] && smallest!=i )
			smallest = 4;
	}

	return smallest;
}

bool isFinished(int board[][11], int size){
	bool control = true;

	int temp = board[size][size];
	board[size][size] = size * size;

	for(int row=1; ( row<=size && control==true ); row++){
		for(int col=1; ( col<=size && control==true ); col++){
			if( board[row][col] != (row-1)*size + col )
				control = false;
		}
	}

	board[size][size] = temp;

	return control;
}