#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

bool compare(const std::string& lhs, const std::string& rhs)
{
	return lhs + rhs > rhs + lhs;
}

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<std::string> arr(N);

	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	if (std::count(arr.begin(), arr.end(), "0") == N)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	std::sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; i++)
		std::cout << arr[i];

	return 0;
}