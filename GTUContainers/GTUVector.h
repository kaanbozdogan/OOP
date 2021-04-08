#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include "GTUContainer.h"

using namespace Bozdogan_CSE241_HW5;


template <typename T>
class GTUVector : public GTUContainer<T>
{
public:
	GTUVector();
	GTUVector(const GTUVector& other);

	T operator [](const int index) const;

	typename GTUVector<T>::GTUIterator insert(typename GTUVector<T>::GTUIteratorConst pos, const T& val);

	typename GTUVector<T>::GTUIterator erase(typename GTUVector<T>::GTUIteratorConst pos);

	typename GTUVector<T>::GTUIterator erase(typename GTUVector<T>::GTUIteratorConst first, typename GTUVector<T>::GTUIteratorConst last);

};

/*----------------------------------------------------------------------------------------------------------------*/

template <typename T>
GTUVector<T>::GTUVector() : GTUContainer<T>()
{/*Intentionay left blank*/}

template <typename T>
GTUVector<T>::GTUVector(const GTUVector& other) : GTUContainer<T>(other)
{/*Intentionay left blank*/}

template <typename T>
T GTUVector<T>::operator [](const int index) const
{
	return GTUContainer<T>::data.get()[index];
}

template <typename T>
typename GTUVector<T>::GTUIterator GTUVector<T>::insert(typename GTUVector<T>::GTUIteratorConst pos, const T& val)
{
	int insertedPos = pos.getIndex(); //Index of value

	if( GTUContainer<T>::needCapacity() ) //Is there a need to increase the capacity
		GTUContainer<T>::increaseCapacity();

	//Starrting from the end each elemet will be shifted one index left until the index which val will be inserted
	for(int i = GTUContainer<T>::dataSize ; i > insertedPos ; i--)
	{
		GTUContainer<T>::data.get()[i] = GTUContainer<T>::data.get()[i-1];	
	}

	//Val inserted into the position wihich is freed for it just before 
	GTUContainer<T>::data.get()[insertedPos] = val;

	//Element count increased
	GTUContainer<T>::dataSize ++;

	return typename GTUVector<T>::GTUIterator( GTUContainer<T>::data, insertedPos); //Iterator which points to the inserted pos
}

template <typename T>
typename GTUVector<T>::GTUIterator GTUVector<T>::erase(typename GTUVector<T>::GTUIteratorConst pos)
{
	int deletedPos = pos.getIndex();

	GTUContainer<T>::dataSize --;

	//Started from the deleted pos each value will be shifted right until the end. So deleted index wont stay empty
	for(int i = deletedPos ; i < GTUContainer<T>::dataSize ; i++)
	{
		GTUContainer<T>::data.get()[i] = GTUContainer<T>::data.get()[i+1];	
	}

	return typename GTUVector<T>::GTUIterator( GTUContainer<T>::data, deletedPos);
}

template <typename T>
typename GTUVector<T>::GTUIterator GTUVector<T>::erase(typename GTUVector<T>::GTUIteratorConst first, typename GTUVector<T>::GTUIteratorConst last)
{
	int deletedCount = 0;
	int deletedPos = first.getIndex();

	for(auto it = first ; it != last ; it++)
	{
		deletedCount ++;
	}

	//Started from the deleted pos each value will be shifted right (x deletedCount) until the end. So deleted indexes wont stay empty
	GTUContainer<T>::dataSize = GTUContainer<T>::dataSize - deletedCount;

	for(int i = deletedPos ; i < GTUContainer<T>::dataSize ; i++ )
	{
		GTUContainer<T>::data.get()[ i ] = GTUContainer<T>::data.get()[ i + deletedCount ];
	}

	return typename GTUVector<T>::GTUIterator( GTUContainer<T>::data, deletedPos);
}


#endif