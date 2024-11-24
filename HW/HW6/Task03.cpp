#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long

std::unordered_map<char, int> uMap;

bool isPossible(std::unordered_map<char, int>& map)
{
	for (auto& el : map)
	{
		if (el.second % 2 == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::string str;
	std::cin >> str;

	std::vector<ll> subsets(str.size() + 1, LLONG_MAX);
	subsets[0] = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (subsets[i] != LLONG_MAX)
		{
			uMap.clear();

			for (int j = i; j < str.size(); j++)
			{
				uMap[str[j]]++;

				if (isPossible(uMap))
				{
					subsets[j + 1] = std::min(subsets[j + 1], subsets[i] + 1);
				}
			}
		}
	}

	std::cout << subsets[str.size()];

	return 0;
}