#include "ClassDef.h"

NPuzzle::NPuzzle(){
	moveCount = 0;
}

bool NPuzzle::readFromFile(const string& fileName){
	moveCount = 0;
	return gameBoard.readFromFile(fileName);
}

bool NPuzzle::writeToFile(const string& fileName) const{
	return gameBoard.writeToFile(fileName);
}

void NPuzzle::printReport() const{
	cout << moveCount << " moves have been done." << endl;

	if( gameBoard.isSolved() )
		cout << "Solution is found!!" << endl;
	else
		cout << "Solution is NOT found..." << endl;
}

bool NPuzzle::setSize(const int& height, const int& width){
	bool control;

	if( height>9 || height<3 || width>9 || width<3 )
		control = false;
	else{
		gameBoard.setSize(height,width);
		reset();
		control = true;
	}

	return control;
}

void NPuzzle::reset(){
	gameBoard.reset();
	moveCount = 0;
}

bool NPuzzle::move(const Direction& dir){
	bool control;

	if( gameBoard.moveControl(dir) ){
		gameBoard.move(dir);
		
		control = true;
	}
	else
		control = false;

	return control;
}

void NPuzzle::moveRandom(){
	Direction direc;

//Loops until it finds the valid direction
	do{
		direc = static_cast<Direction>( rand()%4 );	
	}while( !gameBoard.moveControl(direc) );

//making the valid move
	gameBoard.move(direc);
}

void NPuzzle::shuffle(const int& n){

	for(int count=0; count<n; count++){
		moveRandom();
	}	
}

int NPuzzle::compareHeuristic(int heuristics[4]){
	int smallest = 0;
	bool sameControl = false;

	for(int i=1; i<4; i++){
		if( heuristics[i] < heuristics[smallest] )
			smallest = i;
	}

	return smallest;
}

Direction NPuzzle::moveIntelligent(Direction lastIntelligentMove){
	Direction direc;
	bool direcControls[4];
	int heuristics[4];

	Board boardTemp;

//Controls which directions are valid to move
	for(int i=0; i<4; i++){
		direc = static_cast<Direction>(i);
		direcControls[i] = gameBoard.moveControl(direc);
	}
//negating intelligent move to move to the oposite position of the last intelligent move. Prevents loops
//for exaple if the last move is up, it prevents the current move from being down.
	if( lastIntelligentMove != None ){	
		if( lastIntelligentMove%2 == 0 )
			direcControls[ static_cast<int>(lastIntelligentMove) + 1 ] = false;
		else
			direcControls[ static_cast<int>(lastIntelligentMove) - 1 ] = false;
	}

//tries every direciton
	for(int i=0; i<4; i++){
	//If the direction is valid then it calculates it's heuristics
		if( direcControls[i] ){
			direc = static_cast<Direction>(i);
			boardTemp = gameBoard;

			boardTemp.move(direc);
			heuristics[i] = boardTemp.calcHeuristic();
		}
		else
			heuristics[i] = 2000; //a heuristic value can never be as much as 2000 even in max 9x9 boards
	}

//Does the move with the samallest heurisric	
	direc = static_cast<Direction>( compareHeuristic(heuristics) );

//The board is updated acording to intelligent move
	gameBoard.move(direc);

	return direc;
}

void NPuzzle::solvePuzzle(){
	Direction lastIntelligentMove = None;
	int solveCount = 0;

	while( !gameBoard.isSolved() && solveCount<500 ){
		lastIntelligentMove = moveIntelligent(lastIntelligentMove);
		solveCount ++;

		gameBoard.print();
	}

	while( !gameBoard.isSolved() && solveCount<100000 ){
	//5:15 random/intelligent ratio
		if( solveCount%20==0 ){
			for(int i=0; i<5; i++){
				moveRandom();
				solveCount ++;
				gameBoard.print();
			}
			lastIntelligentMove = None;
		}
		else{
			lastIntelligentMove = moveIntelligent(lastIntelligentMove);
			solveCount ++;

			gameBoard.print();
		}
	}
	moveCount += solveCount;
}