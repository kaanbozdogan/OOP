#include "GTUVector.h"
#include "GTUSet.h"

using namespace Bozdogan_CSE241_HW5;

//I had to define this 2 here because compiler does not alow me to
//implement a template function in 2 seperate files
//Functions find_if and fo_each is taking thoose functions as template parameters


//To test find_if()
bool f(const int& n)
{
	return ( n == 7 );
}

//To test for_each()
void g(const int& n)
{
	cout << n << " ! ";
}



int main()
{	
	GTUVector<int> v;
	GTUVector<int>::GTUIterator itV;
	
	GTUSet<double> s;
	GTUSet<double>::GTUIteratorConst itS;

	GTUVector<ForTesting> t;
	GTUVector<ForTesting>::GTUIterator itT;

	int i;



	cout << endl << endl << endl << endl << endl << endl << endl;

	//VECTOR FUNCTIONS
	cout << "______________________ TRYING VECTOR FUNCTIONS ______________________" << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::size() : "  << v.size() << endl << endl
		<< "--> GTUVector<int>::max_size() : "  << v.max_size() << endl << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> for( i=0 ; i<8 ) { GTUVector<int>::insert(iterator,i) } w/ GTUVector<int>::begin() & GTUVector<int>::end() " << endl << endl;
	
	for(itV = v.begin() , i = 0 ; i < 8 ; itV++ , i++)
	{
		v.insert(itV,i);
	}
	
	cout << "The board:" << endl;
	v.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::size() : "  << v.size() << endl << endl
		<< "--> GTUVector<int>::max_size() : "  << v.max_size() << endl << endl
		<< "--> GTUVector<int>::empty() : ";

	if( v.empty() ) cout << "True" << endl;
	else cout << "False" << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::erase( begin() ) " << endl << endl;
	
	v.erase( v.begin() );
	
	cout << "The board:" << endl;
	v.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::erase( begin() , begin() + 3 ) " << endl << endl;
	
	v.erase( v.begin() , v.begin() + 3 );
	
	cout << "The board:" << endl;
	v.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::clear() " << endl << endl;
	
	v.clear();

	cout << "GTUVector<int>::empty() : ";

	if( v.empty() ) cout << "True" << endl;
	else cout << "False" << endl;


	cout << endl << endl << endl << endl << endl << endl << endl;


	//SET FUNCTIONS
	cout << "______________________ TRYING SET FUNCTIONS ______________________" << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::size() : "  << s.size() << endl << endl
		<< "--> GTUSet<double>::max_size() : "  << s.max_size() << endl << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> for( i=0 ; i<8 ) { GTUSet<double>::insert(iterator,i) } w/ GTUSet<double>::begin() & GTUSet<double>::end() " << endl << endl;
	
	for(itS = s.begin() , i = 0 ; i < 8 ; itS++ , i++)
	{
		s.insert(itS,i);
	}
	
	cout << "The board:" << endl;
	s.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::size() : "  << s.size() << endl << endl
		<< "--> GTUSet<double>::max_size() : "  << s.max_size() << endl << endl
		<< "--> GTUSet<double>::empty() : ";

	if( s.empty() ) cout << "True" << endl;
	else cout << "False" << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::insert( begin() , 6.5 ) --> Even if you give position wrong it will find the true position" << endl << endl;
	
	s.insert( s.begin() , 6.5 );
	
	cout << "The board:" << endl;
	s.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::insert( begin() , 5 ) --> If you try to insert something already exist the task wont be succesfull" << endl << endl;
	
	s.insert( s.begin() , 5 );
	
	cout << "The board:" << endl;
	s.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::erase( begin() ) " << endl << endl;
	
	s.erase( s.begin() );
	
	cout << "The board:" << endl;
	s.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::erase( begin() , begin() + 3 ) " << endl << endl;
	
	s.erase( s.begin() , s.begin() + 3 );
	
	cout << "The board:" << endl;
	s.print();


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::clear() " << endl << endl;
	
	s.clear();

	cout << "GTUSet<double>::empty() : ";

	if( s.empty() ) cout << "True" << endl;
	else cout << "False" << endl;


	cout << endl << endl << endl << endl << endl << endl << endl;


	//ITERATOR FUNCTIONS
	cout << "______________________ TRYING ITERATOR FUNCTIONS ______________________" << endl;
	cout << "_____________________________________________________________________" << endl << endl << endl << endl;

	//Creating a vector to test iterator operators
	for(itV = v.begin() , i = 0 ; i < 10 ; itV++ , i++)
	{
		v.insert(itV,i);
	}

	cout << "              Trying ++, --, * operators for iterator " << endl;
	cout << "_____________________________________________________________________" << endl << endl
		<< "--> for( it = begin() ; it != end() ; it++ ) { cout << *it; } " << endl;

	cout << "--> ";
	for( itV = v.begin() ; itV != v.end() ; itV++ )
	{
		cout << *itV << " | " ;
	}
	cout << endl << endl;


	cout << "--> for( it = end()-1 ; it != begin()-1 ; it-- ) { cout << *it; } " << endl;

	cout << "--> ";
	for( itV = v.end() - 1 ; itV != v.begin() - 1 ; itV-- )
	{
		cout << *itV << " | " ;
	}
	cout << endl;


	cout << "_____________________________________________________________________" << endl << endl;

		itV = v.begin();
		cout << "*it = " << *itV << endl << endl;

		cout << "--> Trying --> *it = 77 " << endl << endl;

		*itV = 77;
		cout << "*it : " << *itV << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::begin() == GTUVector<int>::end() : ";

	if( v.begin() == v.end() )
		cout << "True";
	else
		cout << "False";

	cout << endl << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::begin() != GTUVector<int>::end() : ";

	if( v.begin() != v.end() )
		cout << "True";
	else
		cout << "False";

	cout << endl << endl;

	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<ForTesting>::Iterator::->setA( 5 ) " << endl << endl;
	itT = t.begin();
	itT->setA(5);

	cout << "--> GTUVector<ForTesting>::Iterator::->print() : ";
	itT->print();


	cout << endl << endl << endl << endl << endl << endl << endl;



	//CONST ITERATOR FUNCTIONS
	cout << "______________________ TRYING CONST ITERATOR FUNCTIONS ______________________" << endl;
	cout << "_____________________________________________________________________" << endl << endl << endl << endl;

	//Creating a vector to test iterator operators
	for(itS = s.begin() , i = 0 ; i < 10 ; itS++ , i++)
	{
		s.insert(itS,i);
	}

	cout << "              Trying ++, --, * operators for iterator " << endl;
	cout << "_____________________________________________________________________" << endl << endl
		<< "--> for( it = begin() ; it != end() ; it++ ) { cout << *it; } " << endl;

	cout << "--> ";
	for( itS = s.begin() ; itS != s.end() ; itS++ )
	{
		cout << *itS << " | " ;
	}
	cout << endl << endl;


	cout << "--> for( it = end()-1 ; it != begin()-1 ; it-- ) { cout << *it; } " << endl;

	cout << "--> ";
	for( itS = s.end() - 1 ; itS != s.begin() - 1 ; itS-- )
	{
		cout << *itS << " | " ;
	}
	cout << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::begin() == GTUSet<double>::end() : ";

	if( s.begin() == s.end() )
		cout << "True";
	else
		cout << "False";

	cout << endl << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUSet<double>::begin() != GTUSet<double>::end() : ";

	if( s.begin() != s.end() )
		cout << "True";
	else
		cout << "False";
	cout << endl << endl;


	cout << endl << endl << endl << endl << endl << endl << endl;



	//GLOBAL FUNCTIONS
	cout << "______________________ TRYING GLOBAL FUNCTIONS ______________________" << endl;
	cout << "_____________________________________________________________________" << endl << endl;



	cout << "                               find()" << endl;
	cout << "_____________________________________________________________________" << endl << endl
		<< "--> it = find( vector.begin() , vector.end() , 7 ) " << endl << endl;

	itV = find( v.begin() , v.end() , 7 );

	cout << "   *it = " << *itV << "  ->  Found it" << endl << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> it = find( set.begin() , set.end() , 3 ) " << endl << endl;

	itS = find( s.begin() , s.end() , 3 );

	cout << "   *it = " << *itS << "  ->  Found it" << endl << endl;



	cout << endl << endl;

	cout << "                               find_if()" << endl;
	cout << "_____________________________________________________________________" << endl << endl
		<< "--> it = find_if( vector.begin() , vector.end() , f ) " << endl << endl;

	itV = find_if( v.begin() , v.end() , f );

	cout << "   *it = " << *itV << "  ->  Found it" << endl << endl;


	cout << "_____________________________________________________________________" << endl << endl
		<< "--> it = find_if( set.begin() , set.end() , f ) " << endl << endl;

	itS = find_if( s.begin() , s.end() , f );

	cout << "   *it = " << *itS << "  ->  Found it" << endl << endl;



	cout << endl << endl;

	cout << "                               for_each()" << endl;
	cout << "_____________________________________________________________________" << endl << endl
		<< "--> it = for_each( vector.begin() , vector.end() , g ) " << endl << endl;

	for_each( v.begin() , v.end() , g );

	cout << endl << endl;

	cout << "_____________________________________________________________________" << endl << endl
		<< "--> it = for_each( set.begin() , set.end() , g ) " << endl << endl;

	for_each( s.begin() , s.end() , g );




	cout << endl << endl << endl;
	return 0;
}

/*

	cout << "_____________________________________________________________________" << endl << endl
		<< "--> GTUVector<int>::GTUIterator:: "  << itV << endl << endl;

	itV.();

*/