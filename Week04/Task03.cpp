#include <iostream>
#include <vector>

class Solution
{
public:
	int findMin(std::vector<int>& nums)
	{
		int l = 0, r = nums.size() - 1;

		while (l < r)
		{
			int mid = l + (r - l) / 2;

			if (nums[mid] > nums[r])
			{
				l = mid + 1;
			}
			else if (nums[mid] < nums[l])
			{
				r = mid;
				l++;
			}
			else
			{
				r--;
			}
		}

		return nums[l];
	}
};