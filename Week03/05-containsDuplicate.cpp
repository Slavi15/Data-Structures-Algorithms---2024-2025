#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	bool containsDuplicate(std::vector<int>& nums)
	{
		std::unordered_map<int, bool> uMap;

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (uMap.find(nums[i]) != uMap.end()) return true;
			uMap[nums[i]] = true;
		}

		return false;
	}
};