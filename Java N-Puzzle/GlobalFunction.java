
public class GlobalFunction {

	public static boolean isSequence(AbstractBoard[] sequence, final int size) {
		
		boolean control;
		int i, d;
		Direction direc;

		control=true;
		for(i=0; ( i<size-1 && control==true ); i++)
		{
			control=false;
			for(d=0; ( d<4 && control==false ); d++)
			{
				direc = Direction.intToEnum(d);

				//If move is valid then do it
				if( sequence[i].moveControl(direc) )
				{
					sequence[i].move(direc);
					//If the updated board is equal to the next one then the move is valid
					if( sequence[i].equals( sequence[i+1] ) )
						control = true;

					//Return the board to the state that it was in before trying the move
					if( d%2==0 )
						direc = Direction.intToEnum(d+1);
					else
						direc = Direction.intToEnum(d-1);

					sequence[i].move(direc);
				}
			}
		}

		return control;
		
	}

}
