class Solution
{
public:
	int binarySearch(std::vector<int>& nums, int num, int l, int r)
	{
		if (l > r) return l;

		int mid = l + (r - l) / 2;

		if (num > nums[mid])
			return binarySearch(nums, num, mid + 1, r);
		else if (num < nums[mid])
			return binarySearch(nums, num, l, mid - 1);
		else
			return mid;
	}

	int lengthOfLIS(std::vector<int>& nums)
	{
		std::vector<int> res;

		for (int i = 0; i < nums.size(); i++)
		{
			if (res.empty() || res.back() < nums[i])
			{
				res.push_back(nums[i]);
			}
			else
			{
				int idx = binarySearch(res, nums[i], 0, res.size() - 1);
				res[idx] = nums[i];
			}
		}

		return res.size();
	}
}