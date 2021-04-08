public class Test
{
	public static void main(String[] args)
	{
		GTUVector<Integer> v = new GTUVector<Integer>();
		GTUSet<String> s = new GTUSet<String>();

		GTUIterator<Integer> itV = new GTUIterator<Integer>();
		GTUIterator<String> itS = new GTUIterator<String>();



		System.out.println("\n\n\n");


		System.out.println("___________________ TRYING VECTOR FUNCTIONS ___________________");
		System.out.println("_______________________________________________________________");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUVector<int>.size(): " + v.size() );
		System.out.println( "--> GTUVector<int>.maxSize(): " + v.maxSize() );

		System.out.print( "--> GTUVector<int>.empty(): " );
		if( v.empty() )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> for(i=0;i<10;i++) { GTUVector<int>.insert(i) }" );
		for(int i=0; i<10; i++)
			v.insert(i);

		System.out.println( "Vector-->   " + v.toString() );


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUVector<int>.size(): " + v.size() );
		System.out.println( "--> GTUVector<int>.maxSize(): " + v.maxSize() );

		System.out.print( "--> GTUVector<int>.empty(): " );
		if( v.empty() )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.print( "--> GTUVector<int>.contains(0): " );
		if( v.contains(0) )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUVector<int>.erase(0)" );
		v.erase(0);

		System.out.println( "Vector-->   " + v.toString() );


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.print( "--> GTUVector<int>.contains(0): " );
		if( v.contains(0) )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUVector<int>.clear()" );

		v.clear();


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.print( "--> GTUVector<int>.empty(): " );
		if( v.empty() )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");



		System.out.println("\n\n\n");



		System.out.println("___________________ TRYING SET FUNCTIONS ___________________");
		System.out.println("____________________________________________________________");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUSet<String>.size(): " + s.size() );
		System.out.println( "--> GTUSet<String>.maxSize(): " + s.maxSize() );

		System.out.print( "--> GTUSet<String>.empty(): " );
		if( s.empty() )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUSet<String>.insert(kaan)" );
		System.out.println( "--> GTUSet<String>.insert(can)" );
		System.out.println( "--> GTUSet<String>.insert(onur)" );
		System.out.println( "--> GTUSet<String>.insert(efe)" );

		s.insert("kaan");
		s.insert("can");
		s.insert("onur");
		s.insert("efe");

		System.out.println( "Set-->   " + s.toString() );


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUSet<String>.insert(kaan)" );
		System.out.println("kaan is not added to the set because set can not have duplicates");

		System.out.println( "Set-->   " + s.toString() );


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUSet<String>.size(): " + s.size() );
		System.out.println( "--> GTUSet<String>.maxSize(): " + s.maxSize() );

		System.out.print( "--> GTUSet<String>.empty(): " );
		if( s.empty() )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.print( "--> GTUSet<String>.contains(onur): " );
		if( s.contains("onur") )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUSet<String>.erase(onur)" );
		s.erase("onur");

		System.out.println( "Set-->   " + s.toString() );


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.print( "--> GTUSet<String>.contains(onur): " );
		if( s.contains("onur") )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> GTUSet<String>.clear()" );

		s.clear();


		System.out.println("\n_______________________________________________________________\n\n");
		System.out.print( "--> GTUSet<String>.empty(): " );
		if( s.empty() )
			System.out.println("TRUE");
		else
			System.out.println("FALSE");



		System.out.println("\n\n\n");



		System.out.println("___________________ TRYING ITERATOR FUNCTIONS ___________________");
		System.out.println("_________________________________________________________________");

		for(int i=0; i<10; i++)
			v.insert(i);

		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> Printing vector using GTUIterator.hasNext() and GTUIterator.next()" );

		itV = v.iterator();

		System.out.print("Vector-->   ");

		while( itV.hasNext() )
		{
			System.out.print(itV.next() + " ");
		}



		s.insert("kaan");
		s.insert("can");
		s.insert("onur");
		s.insert("efe");

		System.out.println("\n_______________________________________________________________\n\n");
		System.out.println( "--> Printing set using GTUIterator.hasNext() and GTUIterator.next()" );

		itS = s.iterator();

		System.out.print("Set-->   ");
		while( itS.hasNext() )
		{
			System.out.print(itS.next() + " ");
		}


		System.out.println("\n\n\n");
	}

}