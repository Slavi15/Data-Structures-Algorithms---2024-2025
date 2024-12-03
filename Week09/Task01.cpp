class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		std::unordered_map<int, int> uMap;

		for (int i = 0; i < nums.size(); i++)
		{
			int num = nums[i];

			if (uMap.find(num) != uMap.end() && std::abs(uMap[num] - i) <= k)
			{
				return true;
			}

			uMap[num] = i;
		}

		return false;
	}
};