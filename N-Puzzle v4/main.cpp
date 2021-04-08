#include "ClassDef.h"

using namespace std;


int main(int argc, char* argv[]){
	srand(time(NULL));

	Direction direc;
	Direction lastIntelligentMove = None;
	bool quit = false;
	bool invalid = false;
	int row, col;
	ifstream file;

	NPuzzle puzzle;


	if( argc > 1 ){
		puzzle.readFromFile(argv[1]);
	}
	else{
		do{
			if( invalid )
				cout << endl << "Invalid size values..." << endl;

			cout << "Enter the height: " << endl;
			cin >> col;
			cout << "Enter the width: " << endl;
			cin >> row;

			invalid = !puzzle.setSize(row,col);

		}while ( invalid );

		puzzle.shuffle(row*col);
	}

	char move;
	char fileName[100];

	cout << puzzle;

	do{
		cout << "Your move: ";
		cin >> move;

		while( move!='U' && move!='D' && move!='L' && move!='R' && move!='S' && move!='Q' && move!='V' && move!='T' && move!='E' && move!='O' ){
			cout << endl << "Choose a valid input: ";
			cin >> move;
		}

		switch( move ){
			case 'U':
				direc = Up;

				if( !puzzle.move(direc) )
					invalid = true;
				break;

			case 'D':
				direc = Down;

				if( !puzzle.move(direc) )
					invalid = true;
				break;

			case 'L':
				direc = Left;

				if( !puzzle.move(direc) )
					invalid = true;
				break;

			case 'R':
				direc = Right;

				if( !puzzle.move(direc) )
					invalid = true;
				break;

			case 'S':
				cout << endl << "Shuffling..." << endl;
				puzzle.reset();
				puzzle.shuffle( puzzle.getSizeRow() * puzzle.getSizeCol() );
				break;

			case 'Q':
				cout << "Quiting game..." << endl;
				quit = true;
				break;

			case 'V':
				puzzle.solvePuzzle();
				break;

			case 'T':
				puzzle.printReport();
				break;

			case 'E':
				cout << "Enter the name of the file (with it's extension): ";
				cin >> fileName;
				
				if( puzzle.writeToFile(fileName) )
					cout << "Saved succesfully" << endl;
				else
					cout << "Invalid file" << endl;
				break;

			case 'O':
				cout << "Enter the name of the file (with it's extension): ";
				cin >> fileName;
			//Loading board from file with operator >>
				file.open(fileName);
				if(file.is_open()){
				
					file >> puzzle;
					cout << "Loaded succesfully" << endl;

					file.close();
				}
				else
					cout << "Invalid file" << endl;
/*			Loading board from file with readFromFile()
				if( puzzle.readFromFile(fileName) )
					cout << "Loaded succesfully" << endl;
				else
					cout << "Invalid file" << endl;
*/				break;
		}

	
		if( invalid ){
			cout << "Invalid direction." << endl << endl;
			invalid = false;
		}
		else if( puzzle.isSolved() ){
			puzzle.printReport();
		}

		cout << puzzle;

	}while( quit==false );



	return 0;
}