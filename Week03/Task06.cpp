#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int>& lhs, std::vector<int>& rhs)
{
	return lhs[1] < rhs[1];
}

class Solution
{
public:
	int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
	{
		std::sort(intervals.begin(), intervals.end(), compare);

		int count = 1;
		int prevEnd = intervals[0][1];

		for (size_t i = 1; i < intervals.size(); i++)
		{
			int start = intervals[i][0];
			int end = intervals[i][1];

			if (start >= prevEnd)
			{
				count++;
				prevEnd = end;
			}
		}

		return intervals.size() - count;
	}
};