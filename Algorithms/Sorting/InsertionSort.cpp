template <typename T>
void insertionSort(T* array, size_t size)
{
	if (!array) return;

	for (size_t i = 1; i < size; i++)
	{
		T currentElement = array[i];
		int currentIndex = i - 1;

		while (currentIndex >= 0 && array[currentIndex] > currentElement)
		{
			array[currentIndex + 1] = array[currentIndex--];
		}

		array[currentIndex + 1] = currentElement;
	}
}