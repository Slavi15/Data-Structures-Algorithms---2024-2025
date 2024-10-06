#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int partition(std::vector<int>& arr, int left, int right)
{
	int pivot = arr[right];
	int partitionIndex = left;

	for (size_t i = left; i < right; i++)
	{
		if (arr[i] < pivot)
		{
			std::swap(arr[i], arr[partitionIndex++]);
		}
	}

	std::swap(arr[partitionIndex], arr[right]);
	return partitionIndex;
}

void quickSort(std::vector<int>& arr, int left, int right)
{
	if (left >= right) return;

	int pivotIndex = partition(arr, left, right);

	quickSort(arr, left, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, right);
}

void printArray(const std::vector<int>& arr, size_t size)
{
	int last = -1;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != last) std::cout << arr[i] << " ";
		last = arr[i];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t N = 0;
	std::cin >> N;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	quickSort(arr, 0, N - 1);
	printArray(arr, N);

	return 0;
}