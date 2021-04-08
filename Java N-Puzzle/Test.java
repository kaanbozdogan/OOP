
import java.io.*;

public class Test {

	public static void main(String[] args) {

		BoardArray2D arr2d = new BoardArray2D();
		BoardArray1D arr1d = new BoardArray1D();

		AbstractBoard[] boardArr = new AbstractBoard[5];
		AbstractBoard[] boardArr2 = new AbstractBoard[9];
		int arrSize;
		
		//ARRAY2D FUNCTIONSSystemout.println("____________ TRYING ARRAY2D FUNCTIO\nN);

		
		System.out.println("_________________________________________________\n--> BoardArray2D.setSize(4,4)\n");

		arr2d.setSize(4,4);
		
		System.out.println("The board:");
		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.writeToFile(Array2DOutput.txt)\n");
		
		try{
			arr2d.writeToFile("Array2DOutput.txt");
			System.out.println("Your Board is written to Array2DOutput.txt succesfully.\n");
		}
		catch(IOException e){
			System.out.println("Exception throen ehile writing to file.");
		}


		System.out.println("_________________________________________________\n--> BoardArray2D.numberOfMoves()\n--> BoardArray2D.lastMove()\n");

		System.out.println("Number of Moves: " + arr2d.numberOfMoves() );

		System.out.println("The last move: " + arr2d.lastMove() );



		System.out.println("_________________________________________________\n--> BoardArray2D.move(UP)\n");
		
		if( arr2d.move(Direction.UP) )
			System.out.println("Move done succesfully.");
		else
			System.out.println("Invalid direction for move.");
		
		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.move(RIGHT)\n");
		
		if( arr2d.move(Direction.RIGHT) )
			System.out.println("Move done succesfully.");
		else
			System.out.println("Invalid direction for move.");
		
		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.numberOfMoves()\n--> BoardArray2D.lastMove()\n");

		System.out.println("Number of Moves: " + arr2d.numberOfMoves());

		System.out.println("The last move: " + arr2d.lastMove() );


		System.out.println("_________________________________________________\n--> BoardArray2D.isSolved()\n");
		
		if( arr2d.isSolved() )
			System.out.println("The Board is solved.");
		else
			System.out.println("The board is NOT solved.");

		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.reset()\n");
		
		arr2d.reset();

		System.out.println("Board is reseted succesfully.");
		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.isSolved()\n");
		
		if( arr2d.isSolved() )
			System.out.println("The Board is solved.");
		else
			System.out.println("The board is NOT solved.");

		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.operator(3,3)\n");

		System.out.println("The value at 3rd row and 3rd column is: " + arr2d.cell(3,3));

		System.out.println( arr2d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray2D.readFromFile(InputFile.txt)\n");
		
		try{
			arr2d.readFromFile("InputFile.txt");
			System.out.println("Read from file succesfuly.");
		}
		catch(IOException e){
			System.out.println("Exception thrown while reading from file.");
		}
		
		System.out.println( arr2d.toString() );


		System.out.println("\n\n");



		//ARRAY1D FUNCTIONS
		System.out.println("____________ TRYING ARRAY1D FUNCTIONS ____________");

		
		System.out.println("_________________________________________________\n--> BoardArray1D.setSize(3,3)\n");

		arr1d.setSize(3,3);
		
		System.out.println("The board:");
		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.writeToFile(Array1DOutput.txt)\n");
		
		try{
			arr1d.writeToFile("Array1DOutput.txt");
			System.out.println("Your Board is written to Array2DOutput.txt succesfully\n");
		}
		catch(IOException e){
			System.out.println("Exception thrown while writing to file.");
		}


		System.out.println("_________________________________________________\n--> BoardArray1D.numberOfMoves()\n--> BoardArray1D.lastMove()\n");

		System.out.println("Number of Moves: " + arr1d.numberOfMoves() );

		System.out.println("The last move: " + arr1d.lastMove() );



		System.out.println("_________________________________________________\n--> BoardArray1D.move(UP)\n");
		
		if( arr1d.move(Direction.UP) )
			System.out.println("Move done succesfully.");
		else
			System.out.println("Invalid direction for move.");
		
		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.move(RIGHT)\n");
		
		if( arr1d.move(Direction.RIGHT) )
			System.out.println("Move done succesfully.");
		else
			System.out.println("Invalid direction for move.");
		
		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.numberOfMoves()\n--> BoardArray1D.lastMove()\n");

		System.out.println("Number of Moves: " + arr1d.numberOfMoves());

		System.out.println("The last move: " + arr1d.lastMove() );


		System.out.println("_________________________________________________\n--> BoardArray1D.isSolved()\n");
		
		if( arr1d.isSolved() )
			System.out.println("The Board is solved.");
		else
			System.out.println("The board is NOT solved.");

		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.reset()\n");
		
		arr1d.reset();

		System.out.println("Board is reseted succesfully.");
		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.isSolved()\n");
		
		if( arr1d.isSolved() )
			System.out.println("The Board is solved.");
		else
			System.out.println("The board is NOT solved.");

		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.operator(2,2)\n");

		System.out.println("The value at 2nd row and 2nd column is: " + arr1d.cell(2,2));

		System.out.println( arr1d.toString() );



		System.out.println("_________________________________________________\n--> BoardArray1D.readFromFile(InputFile.txt)\n");
		
		try{
			arr1d.readFromFile("InputFile.txt");
			System.out.println("Read from file succesfuly.");
		}
		catch(IOException e){
			System.out.println("Exception thrown while reading from file.");
		}

		System.out.println( arr1d.toString() );



		System.out.println("\n\n");



		//GLOBAL FUNCTION
		System.out.println("____________ TRYING GLOBAL FUNCTION ____________\n________________________________________________\n");

		arrSize = 5;

		boardArr[0] = new BoardArray2D(3,3);
		boardArr[0].move(Direction.UP);
		boardArr[0].move(Direction.LEFT);
		boardArr[0].move(Direction.UP);
		boardArr[0].move(Direction.LEFT);

		boardArr[1] = new BoardArray1D(3,3);
		boardArr[1].move(Direction.UP);
		boardArr[1].move(Direction.LEFT);
		boardArr[1].move(Direction.UP);

		boardArr[2] = new BoardArray1D(3,3);
		boardArr[2].move(Direction.UP);
		boardArr[2].move(Direction.LEFT);

		boardArr[3] = new BoardArray2D(3,3);
		boardArr[3].move(Direction.UP);

		boardArr[4] = new BoardArray2D(3,3);

		System.out.println("Boards in the array:\n");

		for(int i=0; i<arrSize; i++){
			System.out.println( boardArr[i].toString() );
		}

		System.out.print("Is sequence valid: ");

		if( GlobalFunction.isSequence(boardArr,arrSize) )
			System.out.println("True");
		else
			System.out.println("False");



		System.out.println("________________________________________________\n");

		boardArr[0] = new BoardArray1D(3,3);
		boardArr[0].move(Direction.UP);
		boardArr[0].move(Direction.LEFT);
		boardArr[0].move(Direction.DOWN);
		boardArr[0].move(Direction.LEFT);

		boardArr[1] = new BoardArray2D(3,3);
		boardArr[1].move(Direction.UP);
		boardArr[1].move(Direction.LEFT);
		boardArr[1].move(Direction.DOWN);

		boardArr[2] = new BoardArray1D(3,3);
		boardArr[2].move(Direction.UP);
		boardArr[2].move(Direction.LEFT);

		boardArr[3] = new BoardArray2D(3,3);
		boardArr[3].move(Direction.UP);

		boardArr[4] = new BoardArray2D(3,3);

		System.out.println("Boards in the array:\n");

		for(int i=0; i<arrSize; i++){
			System.out.println( boardArr[i].toString() );
		}

		System.out.print("Is sequence valid: ");

		if( GlobalFunction.isSequence(boardArr,arrSize) )
			System.out.println("True");
		else
			System.out.println("False");



		System.out.println("________________________________________________\n");

		boardArr[0] = new BoardArray1D(3,3);
		boardArr[0].move(Direction.UP);
		boardArr[0].move(Direction.LEFT);
		boardArr[0].move(Direction.LEFT);
		boardArr[0].move(Direction.DOWN);
		boardArr[0].move(Direction.RIGHT);

		boardArr[1] = new BoardArray1D(3,3);
		boardArr[1].move(Direction.UP);
		boardArr[1].move(Direction.LEFT);
		boardArr[1].move(Direction.LEFT);
		boardArr[1].move(Direction.DOWN);

		boardArr[2] = new BoardArray2D(3,3);
		boardArr[2].move(Direction.UP);
		boardArr[2].move(Direction.LEFT);
		boardArr[2].move(Direction.LEFT);

		boardArr[3] = new BoardArray2D(3,3);
		boardArr[3].move(Direction.UP);

		boardArr[4] = new BoardArray2D(3,3);

		System.out.println("Boards in the array:\n");

		for(int i=0; i<arrSize; i++){
			System.out.println( boardArr[i].toString() );
		}

		System.out.print("Is sequence valid: ");

		if( GlobalFunction.isSequence(boardArr,arrSize) )
			System.out.println("True");
		else
			System.out.println("False");



		System.out.println("________________________________________________\n");

		boardArr[0] = new BoardArray2D(3,3);
		boardArr[0].move(Direction.UP);
		boardArr[0].move(Direction.LEFT);
		boardArr[0].move(Direction.UP);
		boardArr[0].move(Direction.LEFT);
		boardArr[0].move(Direction.DOWN);
		boardArr[0].move(Direction.DOWN);

		boardArr[1] = new BoardArray1D(3,3);
		boardArr[1].move(Direction.UP);
		boardArr[1].move(Direction.LEFT);
		boardArr[1].move(Direction.UP);
		boardArr[1].move(Direction.LEFT);
		boardArr[1].move(Direction.DOWN);

		boardArr[2] = new BoardArray2D(3,3);
		boardArr[2].move(Direction.UP);
		boardArr[2].move(Direction.LEFT);
		boardArr[2].move(Direction.UP);
		boardArr[2].move(Direction.LEFT);

		boardArr[3] = new BoardArray1D(3,3);
		boardArr[3].move(Direction.UP);
		boardArr[3].move(Direction.LEFT);

		boardArr[4] = new BoardArray1D(3,3);

		System.out.println("Boards in the array:\n");

		for(int i=0; i<arrSize; i++){
			System.out.println( boardArr[i].toString() );
		}

		System.out.print("Is sequence valid: ");

		if( GlobalFunction.isSequence(boardArr,arrSize) )
			System.out.println("True");
		else
			System.out.println("False");



		System.out.println("________________________________________________\n");

		arrSize = 9;

		boardArr2[0] = new BoardArray1D(4,4);
		boardArr2[0].move(Direction.LEFT);
		boardArr2[0].move(Direction.LEFT);
		boardArr2[0].move(Direction.UP);
		boardArr2[0].move(Direction.LEFT);
		boardArr2[0].move(Direction.UP);
		boardArr2[0].move(Direction.RIGHT);
		boardArr2[0].move(Direction.RIGHT);
		boardArr2[0].move(Direction.UP);

		boardArr2[1] = new BoardArray2D(4,4);
		boardArr2[1].move(Direction.LEFT);
		boardArr2[1].move(Direction.LEFT);
		boardArr2[1].move(Direction.UP);
		boardArr2[1].move(Direction.LEFT);
		boardArr2[1].move(Direction.UP);
		boardArr2[1].move(Direction.RIGHT);
		boardArr2[1].move(Direction.RIGHT);

		boardArr2[2] = new BoardArray2D(4,4);
		boardArr2[2].move(Direction.LEFT);
		boardArr2[2].move(Direction.LEFT);
		boardArr2[2].move(Direction.UP);
		boardArr2[2].move(Direction.LEFT);
		boardArr2[2].move(Direction.UP);
		boardArr2[2].move(Direction.RIGHT);

		boardArr2[3] = new BoardArray1D(4,4);
		boardArr2[3].move(Direction.LEFT);
		boardArr2[3].move(Direction.LEFT);
		boardArr2[3].move(Direction.UP);
		boardArr2[3].move(Direction.LEFT);
		boardArr2[3].move(Direction.UP);

		boardArr2[4] = new BoardArray1D(4,4);
		boardArr2[4].move(Direction.LEFT);
		boardArr2[4].move(Direction.LEFT);
		boardArr2[4].move(Direction.UP);
		boardArr2[4].move(Direction.LEFT);

		boardArr2[5] = new BoardArray2D(4,4);
		boardArr2[5].move(Direction.LEFT);
		boardArr2[5].move(Direction.LEFT);
		boardArr2[5].move(Direction.UP);

		boardArr2[6] = new BoardArray1D(4,4);
		boardArr2[6].move(Direction.LEFT);
		boardArr2[6].move(Direction.LEFT);

		boardArr2[7] = new BoardArray2D(4,4);
		boardArr2[7].move(Direction.LEFT);	

		boardArr2[8] = new BoardArray1D(4,4);

		System.out.println("Boards in the array:\n");

		for(int i=0; i<arrSize; i++){
			System.out.println( boardArr2[i].toString() );
		}

		System.out.print("Is sequence valid: ");

		if( GlobalFunction.isSequence(boardArr2,arrSize) )
			System.out.println("True");
		else
			System.out.println("False");

		System.out.println("\n\n");
	}

}
