template <typename T>
void merge(T* arr, size_t size1, const T* arr2, size_t size2, T* buffer)
{
	if (!arr || !arr2 || !buffer) return;

	size_t arr1Index = 0;
	size_t arr2Index = 0;
	size_t bufferIndex = 0;

	while (arr1Index < size1 && arr2Index < size2)
	{
		if (arr[arr1Index] <= arr2[arr2Index])
		{
			buffer[bufferIndex++] = arr[arr1Index++];
		}
		else
		{
			buffer[bufferIndex++] = arr2[arr2Index++];
		}
	}

	while (arr1Index < size1)
	{
		buffer[bufferIndex++] = arr[arr1Index++];
	}

	while (arr2Index < size2)
	{
		buffer[bufferIndex++] = arr2[arr2Index++];
	}

	size_t length = size1 + size2;
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = buffer[i];
	}
}

template <typename T>
void mergeStep(T* arr, size_t size, T* buffer)
{
	if (!arr || !buffer) return;

	if (size < 2) return;

	size_t mid = size / 2;

	mergeStep(arr, mid, buffer);
	mergeStep(arr + mid, size - mid, buffer);

	merge(arr, mid, arr + mid, size - mid, buffer);
}

template <typename T>
void mergeSort(T* arr, size_t size)
{
	if (!arr || size == 0) return;

	T* buffer = new T[size];

	mergeStep(arr, size, buffer);

	delete[] buffer;
}