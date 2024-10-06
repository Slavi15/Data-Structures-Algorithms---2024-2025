#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t N = 0;
	std::cin >> N;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		(++arr[i]) %= 10;
		if (arr[i] != 0) break;
	}

	if (arr[0] == 0) arr.insert(arr.begin(), 1);

	size_t len = arr.size();
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i];
	}

	return 0;
}