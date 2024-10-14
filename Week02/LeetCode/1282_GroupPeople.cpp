#include <iostream>
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/solutions/4029119/video-solution-explanation-with-drawings-in-depth-c-java/

class Solution
{
public:
	std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes)
	{
		std::vector<std::vector<int>> result;
		std::unordered_map<int, std::vector<int>> uMap;

		for (size_t i = 0; i < groupSizes.size(); i++)
		{
			uMap[groupSizes[i]].push_back(i);

			if (uMap[groupSizes[i]].size() == groupSizes[i])
			{
				result.push_back(uMap[groupSizes[i]]);
				uMap[groupSizes[i]].clear();
			}
		}

		return result;
	}
};