#define ll long long

class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		ll count = 0;
		std::unordered_map<int, int> uMap;

		for (int i = 0; i < nums.size(); i++)
		{
			count += i - uMap[nums[i] - i];
			uMap[nums[i] - i]++;
		}

		return count;
	}
};