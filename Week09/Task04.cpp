class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int count = 0;

		std::unordered_map<int, int> uMap;

		for (int num : nums) uMap[num]++;

		for (auto& kv : uMap)
		{
			if (k == 0)
			{
				if (uMap[kv.first] > 1) count++;
			}
			else
			{
				if (uMap.find(kv.first + k) != uMap.end()) count++;
			}
		}

		return count;
	}
};