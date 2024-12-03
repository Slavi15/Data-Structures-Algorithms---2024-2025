class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int maxLen = 0;

		std::unordered_map<int, int> uMap;

		for (int n : nums) uMap[n]++;

		for (int i = 0; i < nums.size(); i++) {
			int curr = 1;
			int num = nums[i];

			if (uMap.find(num - 1) == uMap.end()) {
				while (uMap.find(num + 1) != uMap.end()) {
					curr++;
					num++;
				}

				maxLen = std::max(maxLen, curr);
			}
		}

		return maxLen;
	}
};