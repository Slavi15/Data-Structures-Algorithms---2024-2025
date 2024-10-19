#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<int> evensOdds(std::vector<int>& arr)
	{
		std::vector<int> even;
		std::vector<int> odd;

		for (size_t i = 0; i < arr.size(); i++)
		{
			(arr[i] % 2 == 0) ? even.push_back(arr[i]) : odd.push_back(arr[i]);
		}

		std::reverse(odd.begin(), odd.end());

		std::vector<int> result(arr.size());

		int resultIndex = 0;
		int left = 0, right = 0;

		while (left < even.size() && right < odd.size())
			result[resultIndex++] = (even[left] < odd[right]) ? even[left++] : odd[right++];

		while (left < even.size())
			result[resultIndex++] = even[left++];

		while (right < odd.size())
			result[resultIndex++] = odd[right++];

		return result;
	}
};