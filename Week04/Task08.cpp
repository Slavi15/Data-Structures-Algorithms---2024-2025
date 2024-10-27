#include <iostream>
#include <vector>

class Solution
{
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
	{
		int l = 0, r = matrix.size() - 1;
		int Mi = -1;

		while (l <= r)
		{
			int mid = l + (r - l) / 2;

			if (target < matrix[mid].front())
			{
				r = mid - 1;
			}
			else if (target > matrix[mid].back())
			{
				l = mid + 1;
			}
			else if (matrix[mid].front() <= target && target <= matrix[mid].back())
			{
				Mi = mid;
				break;
			}
		}

		if (Mi == -1) return false;

		l = 0, r = matrix[Mi].size() - 1;

		while (l <= r)
		{
			int mid = l + (r - l) / 2;

			if (matrix[Mi][mid] == target) return true;

			if (matrix[Mi][mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		return false;
	}
};