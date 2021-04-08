public class GTUSet<T> extends GTUContainer<T> {

	public GTUSet()
	{/*Intentionally left blank*/}

	/**
	 * Constructor that takes an array and casts it to the container
	 * @param array The array that will be casted
	 */
	public GTUSet(final T[] array)
	{
		super(array);
	}

	@Override
	public boolean insert(final T elm) throws IllegalArgumentException {
		boolean control;

		if( contains(elm) )
			control = false;
		else
		{
			if (needCapacity())
				increaseCapacity();

			data[dataCount] = elm;
			dataCount ++;

			control = true;
		}

		return control;
	}

}