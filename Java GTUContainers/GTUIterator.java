public class GTUIterator<T>{

//Fields

	/**
	 * References to container elements.
	 */
	private T[] data;

	/**
	 * Count of elements in the container
	 */
	private int dataCount;
	private int i = 0;

//Methods

	public GTUIterator()
	{/*Intentionally left blank*/}

	/**
	 * Takes an array and casts it to an iterator.
	 * @param array Container elements.
	 */
	@SuppressWarnings("unchecked")
	public GTUIterator(final T[] array, final int size)
	{
		dataCount = size;

		data = (T[]) new Object[dataCount];

		data = array;
	}

	/**
	 * Controls if the container has a next element.
	 * @return true if container has a next element
	 */
	public boolean hasNext()
	{
		return i < dataCount - 1;
	}

	/**
	 * Returns the next element in the iteration.
	 * @return the next element in the iteration
	 */
	public T next()
	{
		i ++;
		return data[i];
	}

}
