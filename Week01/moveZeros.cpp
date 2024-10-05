#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// https://www.hackerrank.com/contests/seminar-01/challenges/-move-zeros/submissions/code/1383612797

int main() {
	size_t N = 0;
	std::cin >> N;

	std::vector<int> arr;

	for (size_t i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	// the loop has to be backwards
	// otherwise consecutive zeros are missed
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] == 0) arr.erase(arr.begin() + i);
		arr.push_back(0);
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}