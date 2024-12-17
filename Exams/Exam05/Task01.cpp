#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool compare(std::pair<int, int>& p1, std::pair<int, int>& p2)
{
	return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
}

void sortDecreasing(int K, std::vector<int>& nums)
{
	std::unordered_map<int, int> mp;

	for (size_t i = 0; i < nums.size(); i++)
	{
		mp[nums[i]]++;
	}

	std::vector<std::pair<int, int>> sorted(mp.begin(), mp.end());

	std::sort(sorted.begin(), sorted.end(), compare);

	for (auto it = sorted.begin(); it != sorted.end() && K > 0; it++)
	{
		std::cout << it->first << " ";
		K--;
	}
}

int main()
{
	int K = 0;
	std::cin >> K;

	std::vector<int> nums{ 11, 7, 4, 5, 11, 2, 5, 5, 11, 7, 10, 3, 10 };

	sortDecreasing(K, nums);

	return 0;
}