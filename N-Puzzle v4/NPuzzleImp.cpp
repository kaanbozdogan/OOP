#include "ClassDef.h"

NPuzzle::NPuzzle(){/*Intentional*/}

NPuzzle::NPuzzle(vector< vector<int> > vector, int eRow, int eCol){
	gameBoard = Board(vector,eRow,eCol);
	boardVector.push_back(gameBoard);
}

bool NPuzzle::readFromFile(const string& fileName){
	bool control;

	boardVector.clear();

	control = gameBoard.readFromFile(fileName);
	
	if( control )
		boardVector.push_back(gameBoard);

	return control;
}

bool NPuzzle::writeToFile(const string& fileName) const{
	return gameBoard.writeToFile(fileName);
}

void NPuzzle::printReport() const{
	if( gameBoard.isSolved() )
		cout << "Solution is found!!" << endl;
	else
		cout << "Solution is NOT found..." << endl;

	cout << gameBoard.getMoveCount() << " moves have been done." << endl;
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
	boardVector.clear();
}

bool NPuzzle::move(const Direction& dir){
	bool control;

	if( gameBoard.moveControl(dir) ){
		gameBoard.move(dir);

		boardVector.clear();
		boardVector.push_back(gameBoard);
		
		control = true;
	}
	else{
		control = false;
	}

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
	gameBoard.resetMoveCount();

	boardVector.clear();
	boardVector.push_back(gameBoard);
}

void NPuzzle::solvePuzzle(){
	Direction dir;
	Board boardTemp;

	int i, d, j;
	bool solved, exists;

	cout << "Solving... Please wait." << endl << endl;
//Goes through whole array and tries possible moves	
	for(i=0, solved=false; ( i<boardVector.size() && solved==false ); i++){
	//Goes through every direction
		for(d=3; ( d>=0 && solved==false ); d--){

		//If the direciton is valid makes it on temp baord
			dir = static_cast<Direction>(d);
			if( boardVector[i].moveControl(dir) ){
				boardTemp = boardVector[i];
				boardTemp.move(dir);
			//Controls if the temp board already exists in vector
				for(j=0, exists=false; j<boardVector.size(); j++){
					if( boardTemp==boardVector[j] ){
						exists = true;
					}
				}
			//If temp board doesnt exist in vector it pushes it and controls it if it is solved
				if( exists==false ){
					boardVector.push_back(boardTemp);

					if( boardTemp.isSolved() )
						solved = true;
				} 
			}
		}
	}

	if( solved ){
	//Game board is initialized with solved board
		gameBoard = boardVector[ boardVector.size()-1 ];
	}
}

ostream& operator <<(ostream& out, const NPuzzle& puzzle){
	puzzle.print();

	return out;
}

istream& operator >>(istream& in, NPuzzle& puzzle){
	vector< vector<int> > temp;
	vector<int> oneRowOfBoard;
	int emptyRow, emptyCol;
	const int border = -1;
	const int empty = 0;

	bool control;
	int row, col;
	char cell[2], dummy;

//Reading to a temporary 2d vector
	for(row=0; row<11; row++){
		oneRowOfBoard.push_back(border);
	}
	temp.push_back(oneRowOfBoard);
	oneRowOfBoard.clear();

	for(row=1, dummy='\n'; dummy=='\n'; row++){ //if there is a new line at the end of the line file continues (not end of the file)	
		oneRowOfBoard.push_back(border);

		for(col=1, dummy=' '; ( dummy==' ' && !in.eof() ); col++){ //if the dummy character is space it is not end of the line yet
			in.get(cell[0]); //first digit of the cell
			in.get(cell[1]); //second digit
			in.get(dummy); //space / new line

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

		temp.push_back(oneRowOfBoard);
		oneRowOfBoard.clear();
	}

	for(row=0; row<11; row++){
		oneRowOfBoard.push_back(border);
	}
	temp.push_back(oneRowOfBoard);

//Turning that temporary 2d vector to an NPuzzle object
	puzzle = NPuzzle(temp,emptyRow,emptyCol);

	return in;
}