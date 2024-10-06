#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
	size_t N = 0;
	std::cin >> N;

	std::unordered_map<int, int> uMap;

	long long max = 0;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;

		if (num > 0)
		{
			if (num > max) max = num;
			uMap[num]++;
		}
	}

	for (long long i = 1; i < max; i++)
	{
		if (uMap.find(i) == uMap.end())
		{
			std::cout << i << std::endl;
			return 0;
		}
	}

	std::cout << max + 1 << std::endl;

	return 0;
}