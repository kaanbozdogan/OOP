#include "SecondHW.h"


void menu(int board[][11], int emptyCell[2], int size[2]){
	char move;
	char fileName[100];

	Direction direc;
	Direction lastIntelligentMove = None;
	
	int moveCount = 0;
	bool quit = false;
	bool invalid = false;

	printControlInf();
	printBoard(board,size);
	
	do{	
		cout << "Your move: ";
		cin >> move;

		while( move!='U' && move!='D' && move!='L' && move!='R' && move!='I' && move!='S' && move!='Q' && move!='V' && move!='T' && move!='E' && move!='Y' ){
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
				lastIntelligentMove = intelligentMove(board,emptyCell,size,lastIntelligentMove);

				cout << endl << "Intelligent move chooses ";
				switch( lastIntelligentMove ){
					case Up:
						cout << "U";
						break;
					case Down:
						cout << "D";
						break;
					case Left:
						cout << "L";
						break;
					case Right:
						cout << "R";
						break;
				}
				cout << endl;
				break;

			case 'S':
				cout << endl << "Shuffling..." << endl;
				shuffle(board,emptyCell,size);
				break;

			case 'Q':
				cout << "Quiting game..." << endl;
				quit = true;
				break;

			case 'V':
				moveCount += solve(board,size,emptyCell);
				break;

			case 'T':
				cout << moveCount << " moves made.";
				if( !isFinished(board,size) )
					cout << "The solution is not found." << endl;
				break;

			case 'E':
				cout << "Enter the name of the file (with it's extension): ";
				cin >> fileName;
				
				if( saveBoard(board,size,fileName) )
					cout << "Saved succesfully" << endl;
				else
					cout << "Invalid file" << endl;
				break;

			case 'Y':
				cout << "Enter the name of the file (with it's extension): ";
				cin >> fileName;

				if( loadBoard(board,size,emptyCell,fileName) )
					cout << "Loaded succesfully" << endl;
				else
					cout << "Invalid file" << endl;
				break;
		}

	
		if( invalid ){
			cout << "Invalid direction." << endl << endl;
			invalid = false;
		}
		else if( isFinished(board,size) )
			cout << "Puzzle solved!!!" << endl << endl;
		else
			moveCount++;


		printBoard(board,size);

	}while( quit==false );

}


bool saveBoard(int board[][11], int size[2], string fileName){
	int row, col;
	bool control = true;

	ofstream file;
	file.open(fileName);

	if( file.is_open() ){
		for(row=1; row<=size[0]; row++){
			for(col=1; col<=size[1]; col++){
				
				if( board[row][col]==empty )
					file << "bb";
				else if( board[row][col]==border )
					file << "00";
				else if( (board[row][col]-10) < 0 )
					file << "0" << board[row][col];
				else
					file << board[row][col];
				
				if( col==size[1] && row!=size[0] )
					file << endl;
				else
					file << " ";
			}
		}
	}
	else
		control = false;

	file.close();

	return control;
}


bool loadBoard(int board[][11], int size[2], int emptyCell[2], string fileName){
	int row, col;
	char cell[2], dummy;

	ifstream file;
	file.open(fileName);
	bool control = true;
	
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
					emptyCell[0] = row;
					emptyCell[1] = col;
				}
				else if( atoi(cell)!=0 ) //if not border
					board[row][col] = atoi(cell);
			}
		}
		size[0] = row-1;
		size[1] = col-1;

		file.close();
	}
	else
		control = false;

	return control;
}


int solve(int board[][11], int size[2], int emptyCell[2]){
	int boardDatabase[ size[0]*size[1] ][11][11];
	int moveCount = 1;

	Direction lastIntelligentMove = None;

	while( !isFinished(board,size) && moveCount<200000 ){
	//if there is a loop it makes random moves
		if( isLoop(board,boardDatabase,size) ){
			for(int i=0; i<100; i++){
				randomMove(board,emptyCell);
				moveCount ++;
			}
		}
		else if( moveCount%300==0 ){ //"make a random move" frequency
			for(int i=0; i<20; i++){
				randomMove(board,emptyCell);
				moveCount ++;
			}
		}
		else{
			lastIntelligentMove = intelligentMove(board,emptyCell,size,lastIntelligentMove);
			moveCount ++;
		}

	//updates the board databse with saving the current board
		updateDatabase(board,boardDatabase,size);

		printBoard(board,size);
	}

	return moveCount;
}


bool isLoop(int board[][11], int boardDatabase[][11][11], int size[2]){
	bool control = false;
	for(int i=0; ( i<size[0]*size[1] && control==false ); i++){ //compares the board with the database
		control = compareBoard(board,boardDatabase[i],size); //if current board is the same with one of the boards in the database
	}

	return control;
}


bool compareBoard(int board[][11], int temp[][11], int size[2]){
	bool control = true;

	for(int i=1; ( i<=size[0] && control==true ); i++){
		for(int j=1; ( j<=size[1] && control==true ); j++){
			if( board[i][j] != temp[i][j] )
				control = false;
		}
	}

	return control;
}


int updateDatabase(int board[][11], int boardDatabase[][11][11], int size[2]){
	int dummy1[2], dummy2[2];
//slide the board
	for(int i=1; i<size[0]*size[1]; i++){
		for(int row=1; row<size[0]; row++){
			for(int col=1; col<size[1]; col++){
				boardDatabase[i][row][col] = boardDatabase[i-1][row][col];
			}
		}
	}
//save the current board to the database
	for(int row=1; row<size[0]; row++){
		for(int col=1; col<size[1]; col++){
			boardDatabase[0][row][col] = board[row][col];
		}
	}
}


Direction intelligentMove(int board[][11], int emptyCell[2], int size[2], Direction lastIntelligentMove){
	Direction direc;
	int boardTemp[11][11], emptyCellTemp[2];
	bool direcControls[4];
	int heuristics[4];

//Controls which directions are valid to move
	for(int i=0; i<4; i++){
		direc = static_cast<Direction>(i);
		direcControls[i] = moveControl(board,emptyCell,direc);
	}
//negating intelligent move to move to the oposite position of the last intelligent move. Prevents loops
//for exaple if the last move is up, it prevents the current move from being down.
	if( lastIntelligentMove%2 == 0 )
		direcControls[ static_cast<int>(lastIntelligentMove) + 1 ] = false;
	else
		direcControls[ static_cast<int>(lastIntelligentMove) - 1 ] = false;

//tries every direciton
	for(int i=0; i<4; i++){
	//If the direction is valid then it calculates it's heuristics
		if( direcControls[i] ){
			direc = static_cast<Direction>(i);

			assignBoard(board,emptyCell,boardTemp,emptyCellTemp);
			updateBoard(boardTemp,emptyCellTemp,direc);
			heuristics[i] = calcHeuristic(boardTemp,size);
		}
		else
			heuristics[i] = 2000; //a heuristic value can never be as much as 2000 in max 9x9 boards
	}

//Does the move with the samallest heurisrics	
	direc = static_cast<Direction>( compareHeuristic(heuristics) );

//The board is updated acording to intelligent move
	updateBoard(board,emptyCell,direc);

	return direc;
}


int calcHeuristic(int board[][11], int size[2]){
	int heuristic = 0;
	int currPos[2], finalPos[2];

	for(int row=1; row<=size[0]; row++){
		for(int col=1; col<=size[1]; col++){

			if( board[row][col]!=empty && board[row][col]!=border ){
				currPos[0] = row;
				currPos[1] = col;
				findFinalPos(board,size,currPos,finalPos); //finds the final position
				heuristic += calcDisstanceToFinalPos(board,currPos,finalPos); //calulates the move count to get to the final position
			}
		}
	}

	return heuristic;
}


void findFinalPos(int board[][11], int size[2], int currPos[2], int finalPos[2]){
	int count = 0;
	bool posFound = false;
	int row, col;

	row=0;//Starting from 0 because row will be incremented at the start. It will start from 1
	while( row<=size[0] && posFound==false ){
		row++; //Incrementing at the start because I dont want the position to be incremented after the position is found

		col=0;
		while( col<=size[1] && posFound==false ){
			col++;
		//counting from the start of the baoard to calculate the fianl position
			if( board[row][col] != border ){
				count++;
			//final position found
				if( board[ currPos[0] ][ currPos[1] ] == count )
					posFound = true;
			}
		}
	}

	finalPos[0] = row;
	finalPos[1] = col;
}


int calcDisstanceToFinalPos(int board[][11], int currPos[2], int finalPos[2]){
	int disstance = 0;
	int difference;

//calculating the diffrence between current position and final position
	difference = currPos[0] - finalPos[0]; 
	if( difference<0 )
		difference = -difference;
	disstance += difference;

	difference = currPos[1] - finalPos[1];
	if( difference<0 )
		difference = -difference;
	disstance += difference;

	return disstance;
}


int compareHeuristic(int heuristics[4]){
	int smallest = 0;
	bool sameControl = false;

	for(int i=1; i<4; i++){
		if( heuristics[i] < heuristics[smallest] )
			smallest = i;
	}

	return smallest;
}