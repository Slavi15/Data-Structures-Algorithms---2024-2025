#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

constexpr size_t MAX_SIZE = 1000;
constexpr size_t MAX_TIME = 7 * 24 * 60;
constexpr size_t MOD = 1000000007;

int dp[MAX_SIZE + 1][MAX_TIME + 1]{ 0 };

int main()
{
	size_t N = 0;
	std::cin >> N;

	std::vector<int> arr(N);

	for (size_t i = 0; i < N; i++)
		std::cin >> arr[i];

	for (size_t i = 0; i <= N; i++)
		dp[i][0] = 1;

	for (size_t i = 1; i <= MAX_SIZE; i++)
	{
		for (size_t j = 1; j <= MAX_TIME; j++)
		{
			(dp[i][j] += dp[i - 1][j]) %= MOD;

			if (j >= arr[i - 1])
			{
				(dp[i][j] += dp[i - 1][j - arr[i - 1]]) %= MOD;
			}
		}
	}

	int res = 0;

	for (size_t i = 1; i <= MAX_TIME; i++)
	{
		res += dp[N][i];
		res %= MOD;
	}

	std::cout << (res + 1) << std::endl;

	return 0;
}