#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

size_t nonDivisibleSubset()
{
	size_t N, K;
	std::cin >> N >> K;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
		std::cin >> arr[i];

	std::vector<int> count(K);

	for (size_t i = 0; i < N; i++)
	{
		int mod = arr[i] % K;
		count[mod]++;
	}

	size_t result = 0;
	result += std::min(count[0], 1);

	size_t halfLength = K / 2;

	if (K % 2 == 0) result += std::min(count[halfLength], 1);

	for (size_t i = 1; i < halfLength; i++)
		if (i != K - i) result += std::min(count[i], count[K - i]);

	return result;
}

int main()
{
	std::cout << nonDivisibleSubset() << std::endl;

	return 0;
}