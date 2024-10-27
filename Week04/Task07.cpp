#include <iostream>
#include <vector>

class Solution
{
public:
	int peakIndexInMountainArray(std::vector<int>& arr)
	{
		int l = 0, r = arr.size() - 1;

		while (l < r)
		{
			int mid1 = l + (r - l) / 3;
			int mid2 = r - (r - l) / 3;

			if (arr[mid1] < arr[mid2])
			{
				l = mid1 + 1;
			}
			else
			{
				r = mid2 - 1;
			}
		}

		return l;
	}
};