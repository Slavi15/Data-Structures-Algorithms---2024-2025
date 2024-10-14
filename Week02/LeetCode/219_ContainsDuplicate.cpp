#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// https://leetcode.com/problems/contains-duplicate-ii/

// Without HashMap
class Solution
{
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k)
	{
		std::vector<std::pair<int, int>> arr;

		for (size_t i = 0; i < nums.size(); i++)
		{
			arr.push_back({ nums[i], i });
		}

		std::sort(arr.begin(), arr.end());

		for (int i = 0; i < arr.size() - 1; i++)
		{
			int nextIndex = i + 1;
			if (arr[i].first == arr[nextIndex].first && std::abs(arr[i].second - arr[nextIndex].second) <= k)
			{
				return true;
			}
		}

		return false;
	}
};

// HashMap Solution
class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		std::unordered_map<int, int> uMap;

		for (int i = 0; i < nums.size(); i++)
		{
			if (uMap.find(nums[i]) != uMap.end() && std::abs(uMap[nums[i]] - i) <= k)
			{
				return true;
			}

			uMap[nums[i]] = i;
		}

		return false;
	}
};