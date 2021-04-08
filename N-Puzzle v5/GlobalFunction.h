#ifndef GLOBAL_H
#define GLOBAL_H

#include "BoardAbstract.h"

using namespace Bozdogan_CSE241_HW5;

/*
//isValidSequence() Algorithm:
//Tries moving to evey direction possible on the cuurent board it is controlling.
//If the current board is eaual to the next board with the move done on it, then the move is valid.
//But if not, then the sequence is not valid.
*/
bool isValidSequence(AbstractBoard* sequence[], const int& size)
{	
	bool control;
	int i, d;
	Direction direc;

	for(i=0, control=true; ( i<size-1 && control==true ); i++)
	{
		for(d=0, control=false; ( d<4 && control==false ); d++)
		{
			direc = static_cast<Direction>(d);

			//If move is valid then do it
			if( sequence[i]->move(direc) )
			{
				//If the updated board is equal to the next one then the move is valid
				if( *sequence[i]==sequence[i+1] )
					control = true;

				//Return the board to the state that it was in before trying the move
				if( d%2==0 )
					direc = static_cast<Direction>(d+1);
				else
					direc = static_cast<Direction>(d-1);

				sequence[i]->move(direc);
			}
		}
	}

	return control;
}

#endif