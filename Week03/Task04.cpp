#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::unordered_map<int, int> uMap;
		std::vector<int> result;

		for (size_t i = 0; i < nums1.size(); i++)
		{
			uMap[nums1[i]]++;
		}

		for (size_t i = 0; i < nums2.size(); i++)
		{
			int num = nums2[i];

			if (uMap.find(num) != uMap.end())
			{
				result.push_back(num);
				uMap[num]--;

				if (uMap[num] == 0) uMap.erase(num);
			}
		}

		return result;
	}
};