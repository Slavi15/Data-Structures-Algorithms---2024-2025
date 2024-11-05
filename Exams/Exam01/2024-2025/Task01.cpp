#include <iostream>
#include <vector>
#include <algorithm>

void findSets(std::vector<int>& arr)
{
	int k = *std::max_element(arr.begin(), arr.end()) + 1;

	std::vector<int> count(k, 0);

	for (size_t i = 0; i < arr.size(); i++)
		count[arr[i]]++;

	int numberSets = *std::max_element(count.begin(), count.end());

	while (numberSets--)
	{
		for (size_t i = 0; i < k; i++)
		{
			if (count[i] > 0)
			{
				std::cout << i << " ";
				count[i]--;
			}
		}

		std::cout << std::endl;
	}
}

int main()
{
	std::vector<int> arr{ 5, 4, 2, 3, 4, 5, 4 };
	std::vector<int> arr1{ 1, 2, 2, 1, 2, 2, 2 };
	std::vector<int> arr2{ 1, 2, 3, 7 };
	std::vector<int> arr3{ 2, 3, 0, 5, 6 };

	findSets(arr);
	findSets(arr1);
	findSets(arr2);
	findSets(arr3);

	return 0;
}