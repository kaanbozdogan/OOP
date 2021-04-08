#include "SecondHW.h"

using namespace std;


int main(int argc, char* argv[]){
	srand(time(NULL));

	int board[11][11];
	int size[2]; //Holds the height and width values of the board
	int emptyCell[2]; //Empty cell coordinates. Don't want to search it every time.

	if( argc > 1 ){
		loadBoard(board,size,emptyCell,argv[1]);
	}
	else{
		size[0] = size[1] = getSize();
		initBoard(board,emptyCell,size);
		shuffle(board,emptyCell,size);
	}

	menu(board,emptyCell,size);


	return 0;
}