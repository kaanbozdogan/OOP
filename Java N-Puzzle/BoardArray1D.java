
import java.io.*;

public final class BoardArray1D extends AbstractBoard {

//Fields
	
	private int[] board;
	

//Methods

	/**
	 *Default constructor
	 */
	public BoardArray1D()
	{/*Intentinaly left blank*/}

	/**
	 *Contructor with Board's row and column size
	 *@param row Count of Board's row
	 *@param col Count of Board's column
	 */	
	public BoardArray1D(final int row, final int col) {
		super(row, col);
		
		setSize(row,col);
	}

	
	@Override
	public String toString() {
		
		String str = new String();
		
		for(int i=0; i<sizeRow; i++){
			
			for(int j=0; j<sizeCol; j++){
				
				if( cell(i+1,j+1)==0 )
					str += "__";
				else
					str = str + Integer.toString( cell(i+1,j+1) );
				
				str += "\t";
			}
			
			str += "\n";
		}
		
		return str;
	}

	
	@Override
	public void readFromFile(String fileName) throws IOException {
		String line = new String();
		char[] digits = new char[2];
		int[] boardTemp = new int[81];
		int row = 0;
		int col = 0;
		
		File file = new File(fileName);
		BufferedReader buffer = new BufferedReader( new FileReader( file ) );
		
		for(row=0; ( line = buffer.readLine() ) !=null; row++)
		{
			for(col=0; col*3<line.length(); col++)
			{
				digits[0] = line.charAt(3*col);
				digits[1] = line.charAt(3*col+1);				
							
				if( digits[0]=='b' ) //it is the blank cell
				{
					boardTemp[ row * (line.length()+1) / 3 + col ] = EMPTY;
					emptyRow = row;
					emptyCol = col;
				}
				else if( Integer.parseInt( String.valueOf(digits) ) != 0 ) //if not border
					boardTemp[ row * (line.length()+1) / 3 + col ] = Integer.parseInt( String.valueOf(digits) );

				else
					boardTemp[ row * (line.length()+1) / 3 + col ] = BORDER;	
			}
		}
		buffer.close();
		
		setSize(row,col);
		
		for(row=0; row<size(); row++)
		{
				board[row] = boardTemp[row];
		}
	}

	
	@Override
	public void writeToFile(String fileName) throws IOException {
		
		FileWriter writer = new FileWriter( fileName );
		
		for(int row=0; row<sizeRow; row++){
			for(int col=0; col<sizeCol; col++){
				
				if( board[getIndexOfCoordinate(row,col)]==EMPTY ) //empty cell
					writer.write("bb");
				else if( board[getIndexOfCoordinate(row,col)]==BORDER ) //border
					writer.write("00");
				else if( (board[getIndexOfCoordinate(row,col)]-10) < 0 ) //one digit number
					writer.write("0" + board[getIndexOfCoordinate(row,col)]);
				else{
					writer.write("" + board[getIndexOfCoordinate(row,col)]); //two digit number
				}
				if( col!=sizeCol-1 ) //not end of line
					writer.write(" ");
				else if( row!=sizeRow-1 ) //end of line but not end of file
					writer.write("\n");
			}
		}
			
		writer.close();
	}
		

	public void setSize(final int row, final int col) {
		
		if( sizeControl(row,col)==true ){
			sizeRow = row;
			sizeCol = col;

			board = new int[size()];
			
			reset();
		}
	}

	
	@Override
	public void reset() {
		
		for(int i=0; i<size(); i++){
			board[i] = i + 1;
		}

		board[size()-1] = EMPTY;
		emptyRow = sizeRow-1;
		emptyCol = sizeCol-1;

		moveCount = 0;
		moveLast = Direction.NONE;
	}

	
	@Override
	public boolean move(Direction direc) {
		
		boolean control;
		int temp, emptyIndex, movedIndex;

		if( moveControl(direc) )
		{
			emptyIndex = getIndexOfCoordinate(emptyRow,emptyCol);

			//Updating the coordinates of empty cell
			switch(direc)
			{
				case UP:
					emptyRow--;
					break;
				case DOWN:
					emptyRow++;
					break;
				case LEFT:
					emptyCol--;
					break;
				case RIGHT:
					emptyCol++;
					break;
				default:
					break;
			}

			movedIndex = getIndexOfCoordinate(emptyRow,emptyCol);

			temp = board[movedIndex];
			board[movedIndex] = EMPTY;
			board[emptyIndex] = temp;
		
			moveCount++;
			moveLast = direc;
			
			control = true;
		}
		else
			control = false;
		
		return control;
		
	}

	@Override
	public boolean isSolved() {

		boolean control = true;

		for(int i=0; ( i<size()-1 && control==true ); i++)
		{
			if( board[i] != i+1 )
				control = false;
		}

		if( board[size()-1]!=EMPTY )
			control = false;

		return control;
	}

	
	@Override
	public int cell(int row, int col) {

		return board[ getIndexOfCoordinate(row-1,col-1) ];
	}

	@Override
	public boolean moveControl(Direction direc) {

		boolean control = false;
		int movedRow = 0, movedCol = 0, movedIndex;

	//Moved coordinates are determined, then controls if the move is not out of board
		switch(direc)
		{
			case UP:
				movedRow = emptyRow - 1;
				movedCol = emptyCol;

				if( movedRow >= 0 )
					control = true;
				break;

			case DOWN:
				movedRow = emptyRow + 1;
				movedCol = emptyCol;

				if( movedRow <= sizeRow-1 )
					control = true;
				break;

			case LEFT:
				movedRow = emptyRow;
				movedCol = emptyCol - 1;

				if( movedCol >= 0 )
					control = true;
				break;

			case RIGHT:
				movedRow = emptyRow;
				movedCol = emptyCol + 1;

				if( movedCol <= sizeCol-1 )
					control = true;
				break;
			
			default :
				control = false;
				break;
		}

	//Controls if the moved cell is a border
		if( control==true )
		{
			movedIndex = getIndexOfCoordinate(movedRow,movedCol);

			if( board[movedIndex]==BORDER )
				control = false;
		}

		return control;
	}
	
	/**
	 *Returns one dimensioned size of the Board.
	 *@return int type.
	 */
	protected int size(){
		
		return sizeRow * sizeCol;
	}

	/**
	 *Returns one dimensional coordiante of given two dimensional cooridiantes.
	 *@return int type.
	 */
	protected int getIndexOfCoordinate(final int row, final int col){
		
		return row * sizeCol + col;
	}
	
	
}
