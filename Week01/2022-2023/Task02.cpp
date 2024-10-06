#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

size_t solve()
{
	size_t N = 0;
	std::cin >> N;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	size_t income = 0;

	for (size_t i = 0; i < N; i++)
	{
		while (arr[i] > arr[i + 1]) i++;
		income -= arr[i];

		while (arr[i] < arr[i + 1]) i++;
		income += arr[i];
	}

	return income;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << solve() << std::endl;

	return 0;
}