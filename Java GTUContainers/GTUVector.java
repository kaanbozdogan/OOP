public class GTUVector<T> extends GTUContainer<T> {

	public GTUVector()
	{/*Intentionally left blank*/}

	/**
	 * Constructor that takes an array and casts it to the container
	 * @param array The array that will be casted
	 */
	public GTUVector(final T[] array)
	{
		super(array);
	}

	@Override
	public boolean insert(final T elm) throws IllegalArgumentException {

		if (needCapacity())
			increaseCapacity();

		data[dataCount] = elm;

		dataCount ++;

		return true;
	}

}