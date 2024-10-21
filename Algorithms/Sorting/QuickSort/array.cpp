#include <iostream>

template <typename T>
size_t partition(T* arr, size_t len)
{
	if (arr[0] > arr[len - 1]) std::swap(arr[0], arr[len - 1]);

	T& pivot = arr[len - 1];
	size_t left = 0, right = len - 1;

	while (true)
	{
		while (arr[++left] < pivot);

		while (arr[--right] > pivot)
		{
			if (left == right) break;
		}

		if (left >= right) break;

		std::swap(arr[left], arr[right]);
	}

	std::swap(arr[left], pivot);
	return left;
}

template <typename T>
void quickSort(T* arr, size_t len)
{
	if (!arr || len < 2) return;

	size_t pivotIndex = partition(arr, len);

	quickSort(arr, pivotIndex);
	quickSort(arr + pivotIndex + 1, len - pivotIndex - 1);
}

int main()
{
	constexpr size_t SIZE = 15;
	int arr[SIZE]{ 15, 14, 13, 12, 11, 30, 90, 8, 7, 6, 5, 4, 3, 2, 1 };

	quickSort(arr, SIZE);

	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";

	return 0;
}