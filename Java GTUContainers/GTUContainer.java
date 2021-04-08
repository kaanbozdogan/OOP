public abstract class GTUContainer<T> {

//Fields

	/**
	 * Field that holds the values in container.
	 */
	protected T[] data;

	/**
	 * Count of data that container holds.
	 */
	protected int dataCount;

	/**
	 * Count of max data that container can hold.
	 */
	protected int capacity;


//Methods

	/**
	 * Default constructor.
	 */
	@SuppressWarnings("unchecked")
	public GTUContainer()
	{
		dataCount = 0;
		capacity = 10;

		data = (T[]) new Object[capacity];
	}

	/**
	 * Constructor that takes an array and casts it to the container.
	 * @param array The array that will be casted.
	 */
	@SuppressWarnings("unchecked")
	public GTUContainer(final T[] array)
	{
		dataCount = array.length;
		capacity = array.length + 10;

		data = (T[]) new Object[capacity];

		for(int i=0; i<dataCount; i++)
			data[i] = array[i];
	}

	/**
	 * Returns true if this set contains no elements.
	 * @return true if this set contains no elements.
	 */
	public boolean empty()
	{
		return dataCount == 0;
	}

	/**
	 * Returns the number of elements in the container.
	 * @return number of elements in the container.
	 */
	public int size()
	{
		return dataCount;
	}

	/**
	 * Returns the number of maximum elements that container can hold.
	 * @return number of maximum elements that container can hold.
	 */
	public int maxSize()
	{
		return capacity;
	}

	/**
	 * Clears all elements in the container.
	 */
	@SuppressWarnings("unchecked")
	public void clear()
	{
		dataCount = 0;
		capacity = 10;

		data = (T[]) new Object[capacity];
	}

	/**
	 * Controls if the container contains the given element.
	 * @param elm Element that wanted to be searched in the container.
	 * @return true if container contains the given element.
	 */
	public boolean contains(final T elm)
	{
		for(int i=0; i<dataCount; i++)
		{
			if(data[i] == elm)
				return true;
		}
		return false;
	}

	/**
	 * Erases the given element from the container.
	 * @param elm Element that wanted to be deleted from the container.
	 * @return true if an element is deleted with this operation.
	 */
	public boolean erase(final T elm) throws IllegalArgumentException {
		boolean found = false;

		for (int i=0 ; i<dataCount; i++)
		{
			//If the element is not found
			if( !found )
			{
				//control if current element is the searched element
				if (data[i] == elm)
					found = true;
			}
			//If element is found shift every element to the left and the element will be deleted
			else
			{
				data[i-1] = data[i];
			}
		}

		if( found )
			dataCount --;

		return found;
	}

	/**
	 * Returns the iterator that points to the first element of the object.
	 */
	public GTUIterator<T> iterator()
	{
		return new GTUIterator<T>(data,dataCount);
	}

	/**
	 * Controls if the container needs to increase its size if an element would be added.
	 * @return true if the container needs to increase its capacity.
	 */
	protected boolean needCapacity()
	{
		return dataCount == capacity;
	}

	/**
	 * Increases the capacity of the container.
	 */
	@SuppressWarnings("unchecked")
	protected void increaseCapacity()
	{
		T[] dataTemp;
		dataTemp = (T[]) new Object[capacity];

		for(int i=0; i<dataCount; i++)
			dataTemp[i] = data[i];

		capacity += 10;
		data = (T[]) new Object[capacity];

		for(int i=0; i<dataCount; i++)
			data[i] = dataTemp[i];
	}

	public String toString()
	{
		StringBuilder str = new StringBuilder();

		for(int i=0; i<dataCount; i++)
		{
			str.append(data[i]);
			str.append(" ");
		}

		return str.toString();
	}

	/**
	 * Inserts the element to the container.
	 * @param elm Element that wanted to be added to the container.
	 * @return true if the element is inserted.
	 */
	abstract public boolean insert(final T elm);

}