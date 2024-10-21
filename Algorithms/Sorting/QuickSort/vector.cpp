#include <iostream>
#include <vector>

size_t partition(std::vector<int>& arr, size_t left, size_t right)
{
	int pivot = arr[right - 1];

	for (size_t i = left; i < right; i++)
	{
		if (arr[i] < pivot)
		{
			std::swap(arr[left++], arr[i]);
		}
	}

	std::swap(arr[left], arr[right - 1]);
	return left;
}

void quickSort(std::vector<int>& arr, size_t left, size_t right)
{
	if (left < right)
	{
		size_t pivotIndex = partition(arr, left, right);
		quickSort(arr, left, pivotIndex);
		quickSort(arr, pivotIndex + 1, right);
	}
}

int main()
{
	std::vector<int> arr{ 15, 14, 13, 12, 11, 30, 90, 8, 7, 6, 5, 4, 3, 2, 1 };

	quickSort(arr, 0, arr.size());

	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";

	return 0;
}