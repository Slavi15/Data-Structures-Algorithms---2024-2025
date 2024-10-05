#include <iostream>

void print(const int* arr, size_t N);

// Min Heap - for reverse sorting
void minHeapify(int* arr, size_t size, size_t nodeIndex)
{
	size_t smallest = nodeIndex;

	size_t leftIndex = 2 * nodeIndex + 1;
	size_t rightIndex = 2 * nodeIndex + 2;

	if (leftIndex < size && arr[leftIndex] < arr[smallest])
	{
		smallest = leftIndex;
	}

	if (rightIndex < size && arr[rightIndex] < arr[smallest])
	{
		smallest = rightIndex;
	}

	if (smallest != nodeIndex)
	{
		std::swap(arr[nodeIndex], arr[smallest]);
		minHeapify(arr, size, smallest);
	}
}

// Max Heap
void heapify(int* arr, size_t size, size_t nodeIndex)
{
	if (!arr) return;

	size_t largest = nodeIndex;

	size_t leftIndex = 2 * nodeIndex + 1;
	size_t rightIndex = 2 * nodeIndex + 2;

	if (leftIndex < size && arr[leftIndex] > arr[largest])
	{
		largest = leftIndex;
	}

	if (rightIndex < size && arr[rightIndex] > arr[largest])
	{
		largest = rightIndex;
	}

	if (largest != nodeIndex)
	{
		std::swap(arr[nodeIndex], arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int* arr, size_t size)
{
	if (!arr) return;

	size_t lastNonLeafIndex = (size / 2) - 1;

	for (int i = lastNonLeafIndex; i >= 0; i--)
	{
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void print(const int* arr, size_t N)
{
	if (!arr) return;

	for (size_t i = 0; i < N; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}

int main()
{
	int arr[11] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	// Max Heap - 17 15 13 9 6 5 10 4 8 3 1

	heapSort(arr, 11);

	print(arr, 11);

	return 0;
}