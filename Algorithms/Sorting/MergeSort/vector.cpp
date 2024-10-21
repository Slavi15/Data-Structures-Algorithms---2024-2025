#include <iostream>
#include <vector>

void merge(std::vector<int>& lhs, std::vector<int>& rhs, std::vector<int>& buffer)
{
	size_t lhsIdx = 0, rhsIdx = 0, bufferIdx = 0;

	while (lhsIdx < lhs.size() && rhsIdx < rhs.size())
		buffer[bufferIdx++] = (lhs[lhsIdx] <= rhs[rhsIdx]) ? lhs[lhsIdx++] : rhs[rhsIdx++];

	while (lhsIdx < lhs.size())
		buffer[bufferIdx++] = lhs[lhsIdx++];

	while (rhsIdx < rhs.size())
		buffer[bufferIdx++] = rhs[rhsIdx++];
}

void mergeStep(std::vector<int>& arr, std::vector<int>& buffer)
{
	if (arr.size() < 2) return;

	size_t mid = arr.size() / 2;

	std::vector<int> lhs(arr.begin(), arr.begin() + mid);
	std::vector<int> rhs(arr.begin() + mid, arr.end());

	mergeStep(lhs, buffer);
	mergeStep(rhs, buffer);

	merge(lhs, rhs, buffer);

	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = buffer[i];
}

void mergeSort(std::vector<int>& arr)
{
	std::vector<int> buffer(arr.size());
	mergeStep(arr, buffer);
}

int main()
{
	std::vector<int> arr{ 15, 14, 13, 12, 11, 30, 90, 8, 7, 6, 5, 4, 3, 2, 1 };

	mergeSort(arr);

	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";

	return 0;
}