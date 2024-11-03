#include <iostream>
#include <vector>

class Solution
{
public:
	int singleNonDuplicate(std::vector<int>& nums)
	{
		int l = 0, r = nums.size() - 1;

		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (mid % 2 != 0) mid--;

			if (nums[mid] == nums[mid + 1])
			{
				l = mid + 2;
			}
			else
			{
				r = mid;
			}
		}

		return nums[l];
	}
};