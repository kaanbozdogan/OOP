#ifndef GTUSET_H
#define	GTUSET_H

#include "GTUContainer.h"

using namespace Bozdogan_CSE241_HW5;

template <typename T>
class GTUSet : public GTUContainer<T>
{
public:
	GTUSet();
	GTUSet(const GTUSet& other);

	typename GTUSet<T>::GTUIterator insert(typename GTUSet<T>::GTUIteratorConst pos, const T& val);

	typename GTUSet<T>::GTUIterator erase (typename GTUSet<T>::GTUIteratorConst pos);

	typename GTUSet<T>::GTUIterator erase (typename GTUSet<T>::GTUIteratorConst first, typename GTUSet<T>::GTUIteratorConst last);

private:
	//Helper function to make set ordered. Finds the proper index of value
	int findPos(const T& val) const;

};

/*----------------------------------------------------------------------------------------------------------------*/

template <typename T>
GTUSet<T>::GTUSet() : GTUContainer<T>()
{/*Intentionaly left blank*/}

template <typename T>
GTUSet<T>::GTUSet(const GTUSet& other) : GTUContainer<T>(other)
{/*Intentionaly left blank*/}

template <typename T>
typename GTUSet<T>::GTUIterator GTUSet<T>::insert(typename GTUSet<T>::GTUIteratorConst pos, const T& val)
{
	int hintedPos = pos.getIndex();
	int insertedPos;

	//If the pos given as an hint is wrong the pos will be calculated pos. Set will stay ordered that way
	if( GTUContainer<T>::data.get()[hintedPos-1] > val
		|| GTUContainer<T>::data.get()[hintedPos] < val )
		insertedPos = findPos(val);

	if( insertedPos != -1 )
	{	
		if( GTUContainer<T>::needCapacity() )
			GTUContainer<T>::increaseCapacity();
	
		//Starrting from the end each elemet will be shifted one index left until the index which val will be inserted
		for(int i = GTUContainer<T>::dataSize ; i > insertedPos ; i--)
		{
			GTUContainer<T>::data.get()[i] = GTUContainer<T>::data.get()[i-1];	
		}
	
		//Val inserted into the position wihich is freed for it just before
		GTUContainer<T>::data.get()[insertedPos] = val;
	
		GTUContainer<T>::dataSize ++;
	}

	return typename GTUSet<T>::GTUIterator( GTUContainer<T>::data, insertedPos);
}

template <typename T>
typename GTUSet<T>::GTUIterator GTUSet<T>::erase(typename GTUSet<T>::GTUIteratorConst pos)
{
	int deletedPos = pos.getIndex();

	GTUContainer<T>::dataSize --;

	for(int i = deletedPos ; i < GTUContainer<T>::dataSize ; i++)
	{
		GTUContainer<T>::data.get()[i] = GTUContainer<T>::data.get()[i+1];	
	}

	return typename GTUSet<T>::GTUIterator( GTUContainer<T>::data, deletedPos);
}

template <typename T>
typename GTUSet<T>::GTUIterator GTUSet<T>::erase(typename GTUSet<T>::GTUIteratorConst first, typename GTUSet<T>::GTUIteratorConst last)
{
	int deletedCount = 0;
	int deletedPos = first.getIndex();

	for(auto it = first ; it != last ; it++)
	{
		deletedCount ++;
	}

	GTUContainer<T>::dataSize = GTUContainer<T>::dataSize - deletedCount;

	for(int i = deletedPos ; i < GTUContainer<T>::dataSize ; i++ )
	{
		GTUContainer<T>::data.get()[ i ] = GTUContainer<T>::data.get()[ i + deletedCount ];
	}

	return typename GTUSet<T>::GTUIterator( GTUContainer<T>::data, deletedPos);
}

template <typename T>
int GTUSet<T>::findPos(const T& val) const
{
	int foundIndex;
	int begin = 0;
	int end = GTUContainer<T>::dataSize;
	int mid;

	//Using binary search algorithm
	while( end - begin > 1 )
	{
		mid = ( begin + end ) / 2;

		if( val < GTUContainer<T>::data.get()[mid] )
			end = mid;

		else if( val > GTUContainer<T>::data.get()[mid] )
			begin = mid;

		else{
			return -1; //If we have the same val already in the set it can not be inserted
		}
	}
	foundIndex = end;

	return foundIndex;
}


#endif