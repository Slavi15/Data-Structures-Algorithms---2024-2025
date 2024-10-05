#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// https://www.hackerrank.com/contests/sda-hw-1-2023/challenges/-6-3/problem

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t N, K;
	std::cin >> N >> K;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	std::sort(arr.begin(), arr.end());

	int min = arr[K - 1] - arr[0];
	size_t subsetsCount = N - K + 1;

	for (size_t i = 0; i < subsetsCount; i++)
	{
		int current = arr[i + K - 1] - arr[i];
		min = std::min(min, current);
	}

	std::cout << min << std::endl;

	return 0;
}