#include <vector>
#include <algorithm>

class Solution
{
public:
	int maximumProduct(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		int start = 0, end = nums.size() - 1;

		int maxStart = nums[start] * nums[start + 1] * nums[end];
		int maxEnd = nums[end] * nums[end - 1] * nums[end - 2];

		return std::max(maxStart, maxEnd);
	}
};