
import java.io.*;


public class BoardArray2D extends AbstractBoard {

//Fields
	
	/**
	 *Board configuration
	 */
	private int[][] board;
	
	
//Methods
	
	/**
	 *Default constructor
	 */
	public BoardArray2D()
	{/*Intentionally left blank*/}

	/**
	 *Contructor with Board's row and column size
	 *@param row Count of Board's row
	 *@param col Count of Board's column
	 */
	public BoardArray2D(int row, int col) {
		super(row, col);
		
		setSize(row,col);
	}

	
	@Override
	public String toString() {
		String str = new String();
		
		for(int i=0; i<sizeRow; i++){
			for(int j=0; j<sizeCol; j++){
				
				if( board[i][j] == EMPTY )
					str += "__";
				else
					str += Integer.toString( board[i][j] );
				
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
		int[][] boardTemp = new int[9][9];
		int row = 0;
		int col = 0;
		
		File file = new File(fileName);
		BufferedReader buffer = new BufferedReader( new FileReader( file ) );
		
		for(row=0; ( line = buffer.readLine() ) != null; row++)
		{
			for(col=0; col*3<line.length(); col++)
			{
				digits[0] = line.charAt(3*col);
				digits[1] = line.charAt(3*col+1);				
							
				if( digits[0]=='b' ) //it is the blank cell
				{
					boardTemp[row][col] = EMPTY;
					emptyRow = row;
					emptyCol = col;
				}
				else if( Integer.parseInt( String.valueOf(digits) ) != 0 ) //if not border
					boardTemp[row][col] = Integer.parseInt( String.valueOf(digits) );

				else
					boardTemp[row][col] = BORDER;	
			}
		}
		buffer.close();
		
		setSize(row,col);
		
		for(row=0; row<sizeRow; row++)
		{
			for(col=0; col<sizeCol; col++)
			{
				board[row][col] = boardTemp[row][col];
			}
		}
		
	}

	
	@Override
	public void writeToFile(String fileName) throws IOException {
	
		FileWriter writer = new FileWriter( fileName );
		
		for(int row=0; row<sizeRow; row++){
			for(int col=0; col<sizeCol; col++){
				
				if( board[row][col]==EMPTY ) //empty cell
					writer.write("bb");
				else if( board[row][col]==BORDER ) //border
					writer.write("00");
				else if( (board[row][col]-10) < 0 ) //one digit number
					writer.write("0" + board[row][col]);
				else{
					writer.write("" + board[row][col]); //two digit number
				}
				if( col!=sizeCol-1 ) //not end of line
					writer.write(" ");
				else if( row!=sizeRow-1 ) //end of line but not end of file
					writer.write("\n");
			}
		}
		
		writer.close();
	}

	@Override
	public void setSize(final int row, final int col) {
		
		if( sizeControl(row,col)==true ){
			sizeRow = row;
			sizeCol = col;

			board = new int[sizeRow][sizeCol];
			
			reset();
		}
	}

	
	@Override
	public void reset() {
		
		for(int i=0; i<sizeRow; i++){
			for(int j=0; j<sizeCol; j++){
				
				board[i][j] = i*sizeCol + j + 1;
			}
		}
		
		board[sizeRow-1][sizeCol-1] = EMPTY;
		emptyRow = sizeRow-1;
		emptyCol = sizeCol-1;

		moveCount = 0;
		moveLast = Direction.NONE;
	}

	
	@Override
	public boolean move(Direction direc) {

		boolean control;
		int temp, movedRow, movedCol;

		if( moveControl(direc) )
		{
			movedCol = emptyCol;
			movedRow = emptyRow;
			
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

			temp = board[ emptyRow ][ emptyCol ];			
			board[ emptyRow ][ emptyCol ] = EMPTY;
			board[ movedRow ][ movedCol ] = temp;
		
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
		int count = 0;
	
		if( sizeRow!=0 )
		{	
			for(int row=0; ( row<sizeRow && control==true ); row++)
			{
				for(int col=0; ( col<sizeCol && control==true ); col++)
				{
					if( board[row][col]!=BORDER )
					{
						count ++;
						if( board[row][col]!=count && board[row][col]!=EMPTY )
							control = false;
					}
				}
			}
		}
		else
			control = false;

		return control;
	}

	
	@Override
	public int cell(int row, int col) {
		
		return board[row-1][col-1];
	}
	
	@Override
	public boolean moveControl(Direction direc) {
		boolean control = false;
		int movedRow=0, movedCol=0;

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
			
			default:
				break;
		}

		if( control ){
			if( board[movedRow][movedCol] == BORDER )
				control = false;
		}

		return control;
	}

	
}
