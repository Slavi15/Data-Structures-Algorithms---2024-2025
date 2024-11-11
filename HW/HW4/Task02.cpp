#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

#define ll long long

int main()
{
	ll N = 0, K = 0;
	std::cin >> N >> K;

	std::vector<ll> arr(N);

	for (ll i = 0; i < N; i++)
		std::cin >> arr[i];

	std::vector<ll> minimumSum;
	std::deque<ll> d;

	for (ll i = 0; i < N; i++)
	{
		while (!d.empty() && d.back() > arr[i]) d.pop_back();
		d.push_back(arr[i]);

		if (i >= K && arr[i - K] == d.front()) d.pop_front();

		if (i >= K - 1) minimumSum.push_back(d.front());
	}

	ll sum = 0;

	for (ll i = 0; i < minimumSum.size(); i++) sum += minimumSum[i];

	std::cout << sum << std::endl;

	return 0;
}