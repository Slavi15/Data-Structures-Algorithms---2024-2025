class Solution {
public:
	int robHelper(std::vector<int>& nums, int start, int end)
	{
		int rob1 = 0;
		int rob2 = 0;

		for (int i = start; i < end; i++)
		{
			int temp = std::max(rob1 + nums[i], rob2);
			rob1 = rob2;
			rob2 = temp;
		}

		return rob2;
	}

	int rob(vector<int>& nums) {
		return std::max({ nums[0], robHelper(nums, 1, nums.size()), robHelper(nums, 0, nums.size() - 1) });
	}
};