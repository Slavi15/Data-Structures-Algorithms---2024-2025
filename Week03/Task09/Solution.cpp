#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	void negativeBeforePositives(std::vector<int>& arr)
	{
		int left = 0, right = arr.size() - 1;

		while (left <= right)
		{
			if (arr[left] > 0 && arr[right] < 0)
			{
				std::swap(arr[left], arr[right]);
				left++;
				right--;
			}
			else if (arr[left] < 0)
			{
				left++;
			}
			else if (arr[right] > 0)
			{
				right--;
			}
		}
	}
};

int main()
{
	std::vector<int> arr{ 3, 6, -5, -1, 5 };

	Solution s;
	s.negativeBeforePositives(arr);

	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";

	return 0;
}