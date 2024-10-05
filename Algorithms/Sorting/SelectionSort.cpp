template <typename T>
void selectionSort(T* array, size_t size)
{
	if (!array) return;

	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minIndex = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			std::swap(array[i], array[minIndex]);
		}
	}
}