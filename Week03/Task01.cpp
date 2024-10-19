#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> sortedSquares(std::vector<int>& nums)
	{
		std::vector<int> result(nums.size());

		int left = 0, right = nums.size() - 1;

		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (std::abs(nums[right]) > std::abs(nums[left]))
			{
				result[i] = nums[right] * nums[right--];
			}
			else
			{
				result[i] = nums[left] * nums[left++];
			}
		}

		return result;
	}
};