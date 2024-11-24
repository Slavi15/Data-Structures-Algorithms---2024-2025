#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long
#define MOD 1000000007;

int main()
{
	ll N = 0;
	std::cin >> N;

	std::vector<ll> dp(N + 1);

	dp[0] = 0;
	dp[1] = 2;

	for (ll i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	std::cout << dp[N] << std::endl;

	return 0;
}