#include <iostream>
#include <vector>
#include <algorithm>

int globalK = 0;

bool compare(std::vector<int>& lhs, std::vector<int>& rhs)
{
	return lhs[globalK] > rhs[globalK];
}

class Solution
{
public:
	std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>>& score, int k)
	{
		globalK = k;
		std::sort(score.begin(), score.end(), compare);
		return score;
	}
};