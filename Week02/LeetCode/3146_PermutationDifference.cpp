#include <iostream>

// https://leetcode.com/problems/permutation-difference-between-two-strings/description/

class Solution
{
public:
	int findPermutationDifference(std::string s, std::string t)
	{
		size_t sum = 0;

		for (int i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			int j = t.find(ch);
			sum += std::abs(i - j);
		}

		return sum;
	}
};