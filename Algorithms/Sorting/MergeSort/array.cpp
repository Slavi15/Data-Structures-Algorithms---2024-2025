#include <iostream>

template <typename T>
void merge(const T* lhs, size_t lhsLen, const T* rhs, size_t rhsLen, T* buffer)
{
	size_t lhsIdx = 0, rhsIdx = 0, bufferIdx = 0;

	while (lhsIdx < lhsLen && rhsIdx < rhsLen)
		buffer[bufferIdx++] = (lhs[lhsIdx] <= rhs[rhsIdx]) ? lhs[lhsIdx++] : rhs[rhsIdx++];

	while (lhsIdx < lhsLen)
		buffer[bufferIdx++] = lhs[lhsIdx++];

	while (rhsIdx < rhsLen)
		buffer[bufferIdx++] = rhs[rhsIdx++];
}

template <typename T>
void mergeStep(T* arr, size_t len, T* buffer)
{
	if (len < 2) return;

	size_t mid = len / 2;

	mergeStep(arr, mid, buffer);
	mergeStep(arr + mid, len - mid, buffer);

	merge(arr, mid, arr + mid, len - mid, buffer);

	for (size_t i = 0; i < len; i++)
		arr[i] = buffer[i];
}

template <typename T>
void mergeSort(T* arr, size_t len)
{
	T* buffer = new T[len]{ 0 };

	mergeStep(arr, len, buffer);

	delete[] buffer;
}

int main()
{
	constexpr size_t SIZE = 15;
	int arr[SIZE]{ 15, 14, 13, 12, 11, 30, 90, 8, 7, 6, 5, 4, 3, 2, 1 };

	mergeSort(arr, SIZE);

	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";

	return 0;
}