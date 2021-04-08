#ifndef NAMESPACE_H
#define NAMESPACE_H

#include<iostream>
#include<memory>

namespace Bozdogan_CSE241_HW5
{
	using std::cout;
	using std::endl;

	using std::shared_ptr;

/*-------------------------- Global Functions --------------------------*/
	template<typename IteratorT, typename T>
	inline IteratorT find(IteratorT first, IteratorT last, const T& val)
	{
		IteratorT it;

		for( it = first ; it != last ; it++ )
		{
			if ( *it == val ) 
				return it;
		}

		return last;
	}


	template<typename IteratorT, typename BooleanT>
	inline IteratorT find_if(IteratorT first, IteratorT last, BooleanT func)
	{
		IteratorT it;

		for( it = first ; it != last ; it++ )
		{
			if ( func(*it) ) 
				return it;
		}

		return last;
	}


	template<typename IteratorT, typename FuncT>
	inline FuncT for_each(IteratorT first, IteratorT last, FuncT func)
	{
		IteratorT it;

		for( it = first ; it != last ; it++ )
		{
			func(*it);
		}

		return func;
	}


/*----------------------- Tester Functions/Classes ---------------------*/
	

	//Class created to trying template container classes
	class ForTesting
	{
	public:
		ForTesting() {};

		void setA(const int& t) { a = t; }
		void print() const { cout << a << endl; };

	private:
		int a;
	};

}


#endif