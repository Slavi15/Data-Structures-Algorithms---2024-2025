#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#include <unordered_map>

// https://www.hackerrank.com/contests/seminar-01/challenges/2sum-11/problem

void findIndices()
{
	size_t N = 0, Z = 0;
	std::cin >> N >> Z;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	std::unordered_map<int, int> uMap;

	for (size_t i = 0; i < arr.size(); i++)
	{
		int complement = Z - arr[i];

		if (uMap.find(complement) != uMap.end())
		{
			std::cout << uMap[complement] << " " << i << std::endl;
			return;
		}

		uMap.insert({ arr[i], i });
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	findIndices();

	return 0;
}