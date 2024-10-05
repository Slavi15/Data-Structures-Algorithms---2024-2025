template <typename T>
size_t partition(T* array, size_t size)
{
	if (!array) return 0;

	T pivot = array[size / 2];

	size_t start = 0;
	size_t end = size - 1;

	while (true)
	{
		while (array[start] < pivot)
			start++;

		while (array[end] > pivot)
			end--;

		if (start < end)
		{
			std::swap(array[start], array[end]);
		}
		else
		{
			return end;
		}
	}
}

template <typename T>
void quickSort(T* array, size_t size)
{
	if (!array) return;

	if (size < 2) return;

	size_t pivotIndex = partition(array, size);

	quickSort(array, pivotIndex);
	quickSort(array + pivotIndex + 1, size - pivotIndex - 1);
}