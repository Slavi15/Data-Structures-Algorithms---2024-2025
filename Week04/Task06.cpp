#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

bool check(std::vector<ll>& arr, ll target, ll goal)
{
	ll time = 0;

	for (ll i = 0; i < arr.size(); i++)
		time += (target / arr[i]);

	return time >= goal;
}

int main()
{
	ll N, K;
	std::cin >> N >> K;

	std::vector<ll> arr(K);

	ll minTime = LLONG_MAX, maxTime = LLONG_MIN;

	for (ll i = 0; i < K; i++)
	{
		std::cin >> arr[i];
		minTime = std::min(minTime, arr[i]);
		maxTime = std::max(maxTime, arr[i]);
	}

	ll l = (N / K) * minTime;
	ll r = (N / K + 1) * maxTime;
	ll res = 0;

	while (l <= r)
	{
		ll mid = l + (r - l) / 2;

		if (check(arr, mid, N))
		{
			res = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	std::cout << res << std::endl;

	return 0;
}