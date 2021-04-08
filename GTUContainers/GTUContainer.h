#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H

#include<iostream>
#include<memory>
#include"Namespace.h"

using namespace Bozdogan_CSE241_HW5;

template <typename T>
class GTUContainer
{
public:

	/*-------------------------Iterator inner class-------------------------*/
	class GTUIterator
	{
	public:
		GTUIterator();
		GTUIterator(const shared_ptr<T>& data, const int& index);

		inline void setDataPtr(const shared_ptr<T>& data) { dataPtr = data; };
		inline void setIndex(const int& i) { index = i; };
		inline int getIndex() { return index; };

		GTUIterator operator ++(); //pre
		GTUIterator operator ++(int dummy); //post
		GTUIterator operator --(); //pre
		GTUIterator operator --(int dummy); //post

		GTUIterator operator +(const int& n);
		GTUIterator operator -(const int& n);

		GTUIterator operator =(const GTUIterator& other);
		bool operator ==(const GTUIterator& other) const;
		bool operator !=(const GTUIterator& other) const;
		
		T& operator *() const;
		T* operator ->() const;

		//GTUContainer and GTUContainerConst classes are hardly different from each other
		//so making them friend does not hurt object oriented programing principles 
		friend class GTUContainer<T>::GTUIteratorConst;

	private:
		shared_ptr<T> dataPtr;
		int index;

	};

	/*----------------------Const iterator inner class----------------------*/
	class GTUIteratorConst
	{
	public:
		GTUIteratorConst();
		GTUIteratorConst(const shared_ptr<T>& data, const int& index);
		GTUIteratorConst(const GTUIterator& other);

		inline void setDataPtr(const shared_ptr<T>& data) { dataPtr = data; };
		inline void setIndex(const int& i) { index = i; };
		inline int getIndex() { return index; };

		GTUIteratorConst operator ++(); //pre
		GTUIteratorConst operator ++(int dummy); //post
		GTUIteratorConst operator --(); //pre
		GTUIteratorConst operator --(int dummy); //post

		GTUIteratorConst operator +(const int& n);
		GTUIteratorConst operator -(const int& n);

		GTUIteratorConst operator =(const GTUIteratorConst& other);
		bool operator ==(const GTUIteratorConst& other) const;
		bool operator !=(const GTUIteratorConst& other) const;
		
		const T& operator *() const;
		const T* operator ->() const;

		friend class GTUContainer<T>::GTUIterator;

	private:
		shared_ptr<T> dataPtr;
		int index;
	};

/*-------------------------Container base class-------------------------*/
	
	GTUContainer();
	GTUContainer(const GTUContainer& other);

	inline int size() const { return dataSize; };
	inline int max_size() const { return capacity; };

	bool empty() const;
	void clear();
	
	typename GTUContainer<T>::GTUIterator begin() const;
	typename GTUContainer<T>::GTUIterator end() const;
	typename GTUContainer<T>::GTUIteratorConst cbegin() const;
	typename GTUContainer<T>::GTUIteratorConst cend() const;

	void print() const;

	/*Pure virtual functions*/
	virtual typename GTUContainer<T>::GTUIterator insert (GTUIteratorConst pos, const T& val) = 0;
	virtual typename GTUContainer<T>::GTUIterator erase (GTUIteratorConst pos) = 0;
	virtual typename GTUContainer<T>::GTUIterator erase (GTUIteratorConst first, GTUIteratorConst last) = 0;
	//Only functions that has same signature for std::set and std::vector are defined in order to make them pure virtual

protected:
	shared_ptr<T> data;

	int dataSize;
	int capacity;

	//Helper functions which wont be needed in public scope
	bool needCapacity() const;
	void increaseCapacity();
};

/*Compiler does not support separate compilation with templates so all the implementations are at this same header file*/

/*---------------------------------Constainer base class function implementations---------------------------------*/

template <typename T>
GTUContainer<T>::GTUContainer() : dataSize(0), capacity(5)
{
	data = shared_ptr<T>( new T[capacity], [](T* d) { delete[] d; } );
}

template <typename T>
GTUContainer<T>::GTUContainer(const GTUContainer& other) : dataSize(other.dataSize), capacity(other.capacity)
{
	data = shared_ptr<T>( new T[capacity], [](T* d) { delete[] d; } );

	for(int i=0; i<dataSize; i++)
		data.get()[i] = other.data.get()[i];
}

template <typename T>
bool GTUContainer<T>::empty() const
{
	if( dataSize == 0 )
		return true;
	else
		return false;
}

template <typename T>
void GTUContainer<T>::clear()
{
	if( dataSize != 0 )
	{
		dataSize = 0;
		capacity = 5;

		data = shared_ptr<T>( new T[capacity], [](T* d) { delete[] d; } );
	}
}

//this function is called when dataSize is increased
template <typename T>
bool GTUContainer<T>::needCapacity() const
{	
	if( dataSize == capacity )
		return true;
	else
		return false;
}

template <typename T>
void GTUContainer<T>::increaseCapacity()
{
	shared_ptr<T> newData;

	//New data with increased capacity
	capacity = capacity + 5;
	newData = shared_ptr<T>( new T[capacity], [](T* d) { delete[] d; } );

	//Data stored until now is copied
	for(int i=0; i<dataSize; i++)
		newData.get()[i] = data.get()[i];

	data = newData;
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::begin() const
{
	return GTUIterator(data,0); //Return an Iterator which points to 0th index
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::end() const
{
	return GTUIterator(data,dataSize); ////Return an Iterator which points to the end of last index
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::cbegin() const
{
	return GTUIteratorConst(data,0);
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::cend() const
{
	return GTUIteratorConst(data,dataSize);
}

template <typename T>
void GTUContainer<T>::print() const
{
	for(auto it = begin() ; it != end() ; it++)
	{
		cout << " " << *it;

		if( it + 1 != end() )
			cout << " |";
		else
			cout << endl;
	}
}

/*------------------------------------Iterator member function implementations------------------------------------*/

template <typename T>
GTUContainer<T>::GTUIterator::GTUIterator()
{/*Intentionaly lrft blank*/}

template <typename T>
GTUContainer<T>::GTUIterator::GTUIterator(const shared_ptr<T>& data, const int& index) 
{
	setDataPtr(data);
	setIndex(index);
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator ++()
{
	index++;

	return GTUIterator(dataPtr,index);
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator ++(int dummy)
{	
	int indexTemp = index;
	
	index++;

	return GTUIterator(dataPtr,indexTemp);
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator --()
{
	index--;

	return GTUIterator(dataPtr,index);
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator --(int dummy)
{	
	int indexTemp = index;
	
	index--;

	return GTUIterator(dataPtr,indexTemp);
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator +(const int& n)
{
	return GTUIterator(dataPtr, index + n );
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator -(const int& n)
{
	return GTUIterator(dataPtr, index - n );
}

template <typename T>
typename GTUContainer<T>::GTUIterator GTUContainer<T>::GTUIterator::operator =(const GTUIterator& other)
{
	dataPtr = other.dataPtr;
	index = other.index;

	return (*this);
}

template <typename T>
bool GTUContainer<T>::GTUIterator::operator ==(const GTUIterator& other) const
{
	//Iterator ppoints to the same data and same index
	if( dataPtr==other.dataPtr && index==other.index )
		return true;
	else
		return false;
}

template <typename T>
bool GTUContainer<T>::GTUIterator::operator !=(const GTUIterator& other) const
{
	return !(*this==other);
}

template <typename T>
T& GTUContainer<T>::GTUIterator::operator *() const
{
	return dataPtr.get()[index];
}

template <typename T>
T* GTUContainer<T>::GTUIterator::operator->() const
{
	return &dataPtr.get()[index];
}

/*---------------------------------Const Iterator member function implementations---------------------------------*/

template <typename T>
GTUContainer<T>::GTUIteratorConst::GTUIteratorConst()
{/*Intentionaly lrft blank*/}

template <typename T>
GTUContainer<T>::GTUIteratorConst::GTUIteratorConst(const shared_ptr<T>& data, const int& index) 
{
	setDataPtr(data);
	setIndex(index);
}

//Constructor to cast non-const itgerator to const iterator
template <typename T>
GTUContainer<T>::GTUIteratorConst::GTUIteratorConst(const GTUIterator& other)
{
	setDataPtr(other.dataPtr);
	setIndex(other.index);
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator ++()
{
	index++;

	return GTUIteratorConst(dataPtr,index);
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator ++(int dummy)
{	
	int indexTemp = index;
	
	index++;

	return GTUIteratorConst(dataPtr,indexTemp);
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator --()
{
	index--;

	return GTUIteratorConst(dataPtr,index);
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator --(int dummy)
{	
	int indexTemp = index;
	
	index--;

	return GTUIteratorConst(dataPtr,indexTemp);
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator +(const int& n)
{
	return GTUIteratorConst(dataPtr, index + n );
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator -(const int& n)
{
	return GTUIteratorConst(dataPtr, index - n );
}

template <typename T>
typename GTUContainer<T>::GTUIteratorConst GTUContainer<T>::GTUIteratorConst::operator =(const GTUIteratorConst& other)
{
	dataPtr = other.dataPtr;
	index = other.index;

	return (*this);
}

template <typename T>
bool GTUContainer<T>::GTUIteratorConst::operator ==(const GTUIteratorConst& other) const
{
	if( dataPtr==other.dataPtr && index==other.index )
		return true;
	else
		return false;
}

template <typename T>
bool GTUContainer<T>::GTUIteratorConst::operator !=(const GTUIteratorConst& other) const
{
	return !(*this==other);
}

template <typename T>
const T& GTUContainer<T>::GTUIteratorConst::operator *() const
{
	return dataPtr.get()[index];
}

template <typename T>
const T* GTUContainer<T>::GTUIteratorConst::operator->() const
{
	return &dataPtr.get()[index];
}


#endif