#include "BoardVector.h"
#include "BoardArray2D.h"
#include "BoardArray1D.h"
#include "GlobalFunction.h"


using namespace Bozdogan_CSE241_HW5;

int main(){
	BoardVector vec;
	BoardArray2D arr2d;
	BoardArray1D arr1d;

	AbstractBoard* boardArr[5];
	AbstractBoard* boardArr2[9];

	int arrSize;


	cout << endl << endl << endl << endl;


//VECTOR FUNCTIONS
	cout << "____________ TRYING VECTOR FUNCTIONS ____________" << endl;


	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.setSize(3,3)" << endl << endl;
	
	vec.setSize(3,3);
	
	cout << "The board:" << endl;
	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.writeToFile(VectorOutput.txt)" << endl << endl;
	
	if( vec.writeToFile("VectorOutput.txt") )
		cout << "Your Board is written to VectorOutput.txt succesfully" << endl << endl;
	else
		cout << "Writing to file failed" << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.numberOfMoves()" << endl
		<< "--> BoardVector.lastMove()" << endl << endl;

	cout << "Number of Moves: " << vec.numberOfMoves() << endl;

	switch( vec.lastMove() )
	{
		case Up:
			cout << "The last move: Up";
			break;
		case Down:
			cout << "The last move: Down";
			break;
		case Left:
			cout << "The last move: Left";
			break;
		case Right:
			cout << "The last move: Right";
			break;
		case None:
			cout << "The last move: None";
			break;
	}
	cout << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.move(Up)" << endl << endl;
	
	if( vec.move(Up) )
		cout << "Move done succesfully." << endl;
	else
		cout << "Invalid direction for move." << endl;
	
	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.move(Right)" << endl << endl;
	
	if( vec.move(Right) )
		cout << "Move done succesfully." << endl;
	else
		cout << "Invalid direction for move." << endl;
	
	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.numberOfMoves()" << endl
		<< "--> BoardVector.lastMove()" << endl << endl;

	cout << "Number of Moves: " << vec.numberOfMoves() << endl;

	switch( vec.lastMove() )
	{
		case Up:
			cout << "The last move: Up";
			break;
		case Down:
			cout << "The last move: Down";
			break;
		case Left:
			cout << "The last move: Left";
			break;
		case Right:
			cout << "The last move: Right";
			break;
		case None:
			cout << "The last move: None";
			break;
	}
	cout << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.isSolved()" << endl << endl;
	
	if( vec.isSolved() )
		cout << "The Board is solved." << endl;
	else
		cout << "The board is NOT solved." << endl;

	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.reset()" << endl << endl;
	
	vec.reset();

	cout << "Board is reseted succesfully." << endl;
	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.isSolved()" << endl << endl;
	
	if( vec.isSolved() )
		cout << "The Board is solved." << endl;
	else
		cout << "The board is NOT solved." << endl;

	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.operator(2,2)" << endl << endl;

	cout << "The value at 2nd row and 2nd column is: " << vec(2,2) << endl;

	vec.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardVector.readFromFile(InputFile.txt)" << endl << endl;
	
	if( vec.readFromFile("InputFile.txt") )
		cout << "Read from file succesfuly." << endl;
	else
		cout << "Invalid file." << endl;

	vec.print();



	cout << endl << endl << endl << endl;


//ARRAY2D FUNCTIONS
	cout << "____________ TRYING ARRAY2D FUNCTIONS ____________" << endl;

	
	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.setSize(4,4)" << endl << endl;

	arr2d.setSize(4,4);
	
	cout << "The board:" << endl;
	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.writeToFile(Array2DOutput.txt)" << endl << endl;
	
	if( arr2d.writeToFile("Array2DOutput.txt") )
		cout << "Your Board is written to Array2DOutput.txt succesfully" << endl << endl;
	else
		cout << "Writing to file failed" << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.numberOfMoves()" << endl
		<< "--> BoardArray2D.lastMove()" << endl << endl;

	cout << "Number of Moves: " << arr2d.numberOfMoves() << endl;

	switch( arr2d.lastMove() )
	{
		case Up:
			cout << "The last move: Up";
			break;
		case Down:
			cout << "The last move: Down";
			break;
		case Left:
			cout << "The last move: Left";
			break;
		case Right:
			cout << "The last move: Right";
			break;
		case None:
			cout << "The last move: None";
			break;
	}
	cout << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.move(Up)" << endl << endl;
	
	if( arr2d.move(Up) )
		cout << "Move done succesfully." << endl;
	else
		cout << "Invalid direction for move." << endl;
	
	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.move(Right)" << endl << endl;
	
	if( arr2d.move(Right) )
		cout << "Move done succesfully." << endl;
	else
		cout << "Invalid direction for move." << endl;
	
	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.numberOfMoves()" << endl
		<< "--> BoardArray2D.lastMove()" << endl << endl;

	cout << "Number of Moves: " << arr2d.numberOfMoves() << endl;

	switch( arr2d.lastMove() )
	{
		case Up:
			cout << "The last move: Up";
			break;
		case Down:
			cout << "The last move: Down";
			break;
		case Left:
			cout << "The last move: Left";
			break;
		case Right:
			cout << "The last move: Right";
			break;
		case None:
			cout << "The last move: None";
			break;
	}
	cout << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.isSolved()" << endl << endl;
	
	if( arr2d.isSolved() )
		cout << "The Board is solved." << endl;
	else
		cout << "The board is NOT solved." << endl;

	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.reset()" << endl << endl;
	
	arr2d.reset();

	cout << "Board is reseted succesfully." << endl;
	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.isSolved()" << endl << endl;
	
	if( arr2d.isSolved() )
		cout << "The Board is solved." << endl;
	else
		cout << "The board is NOT solved." << endl;

	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.operator(3,3)" << endl << endl;

	cout << "The value at 3rd row and 3rd column is: " << arr2d(3,3) << endl;

	arr2d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray2D.readFromFile(InputFile.txt)" << endl << endl;
	
	if( arr2d.readFromFile("InputFile.txt") )
		cout << "Read from file succesfuly." << endl;
	else
		cout << "Invalid file." << endl;

	arr2d.print();



	cout << endl << endl << endl << endl;


//ARRAY1D FUNCTIONS
	cout << "____________ TRYING ARRAY1D FUNCTIONS ____________" << endl;

	

	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.setSize(5,5)" << endl << endl;
	
	arr1d.setSize(5,5);
	
	cout << "The board:" << endl;
	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.writeToFile(Array1DOutput.txt)" << endl << endl;
	
	if( arr1d.writeToFile("Array1DOutput.txt") )
		cout << "Your Board is written to Array1DOutput.txt succesfully" << endl << endl;
	else
		cout << "Writing to file failed" << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.numberOfMoves()" << endl
		<< "--> BoardArray1D.lastMove()" << endl << endl;

	cout << "Number of Moves: " << arr1d.numberOfMoves() << endl;

	switch( arr1d.lastMove() )
	{
		case Up:
			cout << "The last move: Up";
			break;
		case Down:
			cout << "The last move: Down";
			break;
		case Left:
			cout << "The last move: Left";
			break;
		case Right:
			cout << "The last move: Right";
			break;
		case None:
			cout << "The last move: None";
			break;
	}
	cout << endl << endl;



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.move(Up)" << endl << endl;
	
	if( arr1d.move(Up) )
		cout << "Move done succesfully." << endl;
	else
		cout << "Invalid direction for move." << endl;
	
	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.move(Right)" << endl << endl;
	
	if( arr1d.move(Right) )
		cout << "Move done succesfully." << endl;
	else
		cout << "Invalid direction for move." << endl;
	
	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.numberOfMoves()" << endl
		<< "--> BoardArray1D.lastMove()" << endl << endl;

	cout << "Number of Moves: " << arr1d.numberOfMoves() << endl;

	switch( arr1d.lastMove() )
	{
		case Up:
			cout << "The last move: Up";
			break;
		case Down:
			cout << "The last move: Down";
			break;
		case Left:
			cout << "The last move: Left";
			break;
		case Right:
			cout << "The last move: Right";
			break;
		case None:
			cout << "The last move: None";
			break;
	}
	cout << endl << endl;


	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.isSolved()" << endl << endl;
	
	if( arr1d.isSolved() )
		cout << "The Board is solved." << endl;
	else
		cout << "The board is NOT solved." << endl;

	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.reset()" << endl << endl;
	
	arr1d.reset();

	cout << "Board is reseted succesfully." << endl;
	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.isSolved()" << endl << endl;
	
	if( arr1d.isSolved() )
		cout << "The Board is solved." << endl;
	else
		cout << "The board is NOT solved." << endl;

	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.operator(4,4)" << endl << endl;

	cout << "The value at 3rd row and 3rd column is: " << arr1d(4,4) << endl;

	arr1d.print();



	cout << "_________________________________________________" << endl << endl
		<< "--> BoardArray1D.readFromFile(InputFile.txt)" << endl << endl;
	
	if( arr1d.readFromFile("InputFile.txt") )
		cout << "Read from file succesfuly." << endl;
	else
		cout << "Invalid file." << endl;

	arr1d.print();



	cout << endl;

	cout << "____________ TRYING STATIC FUNCTIONS ____________" << endl;


	cout << "_________________________________________________" << endl << endl
		<< "--> AbstarctBoard::numberOfBoards()" << endl << endl;
	
	cout << "Number of boards: " << AbstractBoard::numberOfBoards() << endl << endl
		<< "_________________________________________________";



	cout << endl << endl << endl << endl;

	
	cout << "____________ TRYING GLOBAL FUNCTION ____________" << endl;
	

	cout << "________________________________________________" << endl << endl;

	arrSize = 5;

	boardArr[0] = new BoardArray2D(3,3);
	boardArr[0]->move(Up);
	boardArr[0]->move(Left);
	boardArr[0]->move(Up);
	boardArr[0]->move(Left);

	boardArr[1] = new BoardVector(3,3);
	boardArr[1]->move(Up);
	boardArr[1]->move(Left);
	boardArr[1]->move(Up);

	boardArr[2] = new BoardArray1D(3,3);
	boardArr[2]->move(Up);
	boardArr[2]->move(Left);

	boardArr[3] = new BoardArray2D(3,3);
	boardArr[3]->move(Up);

	boardArr[4] = new BoardVector(3,3);

	cout << "Boards in the array:" << endl << endl;

	for(int i=0; i<arrSize; i++)
		boardArr[i]->print();

	cout << "Is sequence valid: ";

	if( isValidSequence(boardArr,arrSize) )
		cout << "True" << endl;
	else
		cout << "False" << endl;

	for(int i=0; i<arrSize; i++)
		delete boardArr[i];

	cout << "________________________________________________" << endl << endl;

	boardArr[0] = new BoardVector(3,3);
	boardArr[0]->move(Up);
	boardArr[0]->move(Left);
	boardArr[0]->move(Down);
	boardArr[0]->move(Left);

	boardArr[1] = new BoardArray2D(3,3);
	boardArr[1]->move(Up);
	boardArr[1]->move(Left);
	boardArr[1]->move(Down);

	boardArr[2] = new BoardArray1D(3,3);
	boardArr[2]->move(Up);
	boardArr[2]->move(Left);

	boardArr[3] = new BoardVector(3,3);
	boardArr[3]->move(Up);

	boardArr[4] = new BoardArray2D(3,3);

	cout << "Boards in the array:" << endl << endl;

	for(int i=0; i<arrSize; i++)
		boardArr[i]->print();

	cout << "Is sequence valid: ";

	if( isValidSequence(boardArr,arrSize) )
		cout << "True" << endl;
	else
		cout << "False" << endl;

	for(int i=0; i<arrSize; i++)
		delete boardArr[i];

	cout << "________________________________________________" << endl << endl;

	boardArr[0] = new BoardArray1D(3,3);
	boardArr[0]->move(Up);
	boardArr[0]->move(Left);
	boardArr[0]->move(Left);
	boardArr[0]->move(Down);
	boardArr[0]->move(Right);

	boardArr[1] = new BoardArray1D(3,3);
	boardArr[1]->move(Up);
	boardArr[1]->move(Left);
	boardArr[1]->move(Left);
	boardArr[1]->move(Down);

	boardArr[2] = new BoardVector(3,3);
	boardArr[2]->move(Up);
	boardArr[2]->move(Left);
	boardArr[2]->move(Left);

	boardArr[3] = new BoardVector(3,3);
	boardArr[3]->move(Up);

	boardArr[4] = new BoardArray2D(3,3);

	cout << "Boards in the array:" << endl << endl;

	for(int i=0; i<arrSize; i++)
		boardArr[i]->print();

	cout << "Is sequence valid: ";

	if( isValidSequence(boardArr,arrSize) )
		cout << "True" << endl;
	else
		cout << "False" << endl;

	for(int i=0; i<arrSize; i++)
		delete boardArr[i];

	cout << "________________________________________________" << endl << endl;

	boardArr[0] = new BoardVector(3,3);
	boardArr[0]->move(Up);
	boardArr[0]->move(Left);
	boardArr[0]->move(Up);
	boardArr[0]->move(Left);
	boardArr[0]->move(Down);
	boardArr[0]->move(Down);

	boardArr[1] = new BoardArray1D(3,3);
	boardArr[1]->move(Up);
	boardArr[1]->move(Left);
	boardArr[1]->move(Up);
	boardArr[1]->move(Left);
	boardArr[1]->move(Down);

	boardArr[2] = new BoardArray2D(3,3);
	boardArr[2]->move(Up);
	boardArr[2]->move(Left);
	boardArr[2]->move(Up);
	boardArr[2]->move(Left);

	boardArr[3] = new BoardArray1D(3,3);
	boardArr[3]->move(Up);
	boardArr[3]->move(Left);

	boardArr[4] = new BoardVector(3,3);

	cout << "Boards in the array:" << endl << endl;

	for(int i=0; i<arrSize; i++)
		boardArr[i]->print();

	cout << "Is sequence valid: ";

	if( isValidSequence(boardArr,arrSize) )
		cout << "True" << endl;
	else
		cout << "False" << endl;

	for(int i=0; i<arrSize; i++)
		delete boardArr[i];

	cout << "________________________________________________" << endl << endl;

	arrSize = 9;

	boardArr2[0] = new BoardArray1D(4,4);
	boardArr2[0]->move(Left);
	boardArr2[0]->move(Left);
	boardArr2[0]->move(Up);
	boardArr2[0]->move(Left);
	boardArr2[0]->move(Up);
	boardArr2[0]->move(Right);
	boardArr2[0]->move(Right);
	boardArr2[0]->move(Up);

	boardArr2[1] = new BoardArray2D(4,4);
	boardArr2[1]->move(Left);
	boardArr2[1]->move(Left);
	boardArr2[1]->move(Up);
	boardArr2[1]->move(Left);
	boardArr2[1]->move(Up);
	boardArr2[1]->move(Right);
	boardArr2[1]->move(Right);

	boardArr2[2] = new BoardVector(4,4);
	boardArr2[2]->move(Left);
	boardArr2[2]->move(Left);
	boardArr2[2]->move(Up);
	boardArr2[2]->move(Left);
	boardArr2[2]->move(Up);
	boardArr2[2]->move(Right);

	boardArr2[3] = new BoardArray1D(4,4);
	boardArr2[3]->move(Left);
	boardArr2[3]->move(Left);
	boardArr2[3]->move(Up);
	boardArr2[3]->move(Left);
	boardArr2[3]->move(Up);

	boardArr2[4] = new BoardArray2D(4,4);
	boardArr2[4]->move(Left);
	boardArr2[4]->move(Left);
	boardArr2[4]->move(Up);
	boardArr2[4]->move(Left);

	boardArr2[5] = new BoardVector(4,4);
	boardArr2[5]->move(Left);
	boardArr2[5]->move(Left);
	boardArr2[5]->move(Up);

	boardArr2[6] = new BoardArray1D(4,4);
	boardArr2[6]->move(Left);
	boardArr2[6]->move(Left);

	boardArr2[7] = new BoardArray2D(4,4);
	boardArr2[7]->move(Left);	

	boardArr2[8] = new BoardVector(4,4);

	cout << "Boards in the array:" << endl << endl;

	for(int i=0; i<arrSize; i++)
		boardArr2[i]->print();

	cout << "Is sequence valid: ";

	if( isValidSequence(boardArr2,arrSize) )
		cout << "True" << endl;
	else
		cout << "False" << endl;

	for(int i=0; i<arrSize; i++)
		delete boardArr2[i];



	cout << endl << endl << endl;

	return 0;
}