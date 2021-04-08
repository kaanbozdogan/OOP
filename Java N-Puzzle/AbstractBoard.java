import java.io.*;


/**
 *Abstract super class of BoardArray2D and BoardArray1D
 *
 * @author KaanCanBozdogan
 * @version 1.0.0
 */
public abstract class AbstractBoard {

//Fields
	
	/**
	 *Count of Board's rows.
	 */
	protected int sizeRow;
	
	/**
	 *Count of Board's columns.
	 */
	protected int sizeCol;

	/**
	 *Row index of Empty cell.
	 */
	protected int emptyRow;
	
	/**
	 *Column index of Empty cell.
	 */
	protected int emptyCol;

	
	/**
	 *Direction of the last move.
	 */
	protected Direction moveLast;
	
	/**
	 *Count of moves that has been done on Board.
	 */
	protected int moveCount;
	
	/**
	 *Count of existing Boards.
	 */
	protected static int boardCount = 0;
	
	/**
	 *Value of Empty cell.
	 */
	static final int EMPTY = 0;
	
	/**
	 *Value of Border cell.
	 */
	static final int BORDER = -1;
	

//Methods
	
	/**
	*Default constructor.
	*/	
	public AbstractBoard() {
		sizeRow = 0;
		sizeCol = 0;
		
		emptyRow = 0;
		emptyCol = 0;
		
		moveLast = Direction.NONE;
		moveCount = 0;
		boardCount ++;
	}

	/**
	*Contructor with Board's row and column size.
	*@param row Count of Board's row.
	*@param col Count of Board's column.
	*/
	public AbstractBoard(final int row, final int col) {		
		
		this();
		
		if( sizeControl(row,col) ){
			sizeRow = row;
			sizeCol = col;
		}
	}
	
	/**
	 *Transforms Board's configuration to string.
	 */
	abstract public String toString();
	
	/**
	 *Reads configuration of Board from file.
	 *@param fileName Name of the file to read from.
	 *@exception IOException Throws exception if something goes wrong while inputing values.
	 */
	abstract public void readFromFile(final String fileName) throws IOException;
	
	/**
	 *Writes configuration of Board to file.
	 *@param fileName Name of the file to write to.
	 *@exception IOException Throws exception if something goes wrong while outputing values.
	 */
	abstract public void writeToFile(final String fileName) throws IOException;
	
	/**
	 *Resets the Board to the final configuration.
	 */
	abstract public void reset();
	
	/**
	 *Sets the size if given size values are valid.
	 *@param row Counf of Board's rows.
	 *@param col Counf of Board's columns.
	 */
	abstract public void setSize(final int row, final int col);
	
	/**
	*Move the Empty cell to a valid Direction.
	*@param direc Direction of the move.
	*@return Returns true if the move is valid, false if the move is invalid.
	*/
	abstract public boolean move(final Direction direc);
	
	/**
	 *Checks if the Board is at final state.
	 *@return Returns true if the Board is solved, false if its not.
	 */
	abstract public boolean isSolved();
	
	/**
	 *Value at the given coordinate.
	 *@param row Row coordinate of the wanted value.
	 *@param col Column coordinate of the wanted value.
	 *@return Returns the int value at the given coordinates.
	 */
	abstract public int cell(final int row, final int col);
	
	/**
	 *Checks if the boards are equal.
	 *@param other The compared Board.
	 *@return Returns true if Board configurations are the same, false if not.
	 */
	public boolean equals(final AbstractBoard other) {
		boolean control = true;
		
		if( !( sizeRow==other.getSizeRow() ) || !( sizeCol==other.getSizeCol() ) )
			control = false;
		
		for(int i=1; ( i<=sizeRow && control==true ); i++)
		{
			for(int j=1; ( j<=sizeCol && control==true ); j++)
			{
				if( this.cell(i,j) != other.cell(i,j) )
					control = false;
			}
		}

		return control;
	}
	
	/**
	 *Constrols if given sizes are valid for a Board size.
	 *@param row Row count that wanted to be checked.
	 *@param col Column count that wanted to be checked.
	 *@return Returns true if given values are valid size values for a Board, false if not.
	 */
	protected boolean sizeControl(final int row, final int col) {
		
		if( row>9 || row<3 || col>9 || col<3 )
			return false;

		else
			return true;
	}
	
	/**
	 *Checks if the move is valid for the Board.
	 *@param direc Direction of the move.
	 *@return Returns true if the move is valid, false if not.
	 */
	abstract public boolean moveControl(Direction direc);
	
	/**
	 *Returns count of Board's rows.
	 *@return int type.
	 */
	public int getSizeRow() {
		return sizeRow;
	}

	/**
	 *Returns count of Board's columns.
	 *@return int type.
	 */
	public int getSizeCol() {
		return sizeCol;
	}
	
	/**
	 *Returns Board's last move.
	 *@return Direction type.
	 */
	public Direction lastMove() {
		return moveLast;
	}
	
	/**
	 *Returns count of moves the Board has done.
	 *@return int type.
	 */
	public int numberOfMoves() {
		return moveCount;
	}

	/**
	 *Returns count of existing Boards.
	 *@return type.
	 */
	public static int NumberOfBoards() {
		return boardCount;
	}
	
}
