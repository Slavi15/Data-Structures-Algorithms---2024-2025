#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

bool check(std::vector<ll>& arr, ll target, ll goal)
{
	ll currentSum = 0;

	for (ll i = 0; i < arr.size(); i++)
	{
		currentSum += (target / arr[i]);
	}

	return currentSum <= goal;
}

int main()
{
	ll n, k;
	std::cin >> n >> k;

	std::vector<ll> arr(k);

	ll minTime = LLONG_MAX, maxTime = LLONG_MIN;

	for (ll i = 0; i < k; i++)
	{
		std::cin >> arr[i];
		minTime = std::min(minTime, arr[i]);
		maxTime = std::max(maxTime, arr[i]);
	}

	ll left = (n / k) * minTime;
	ll right = (n / k + 1) * maxTime;
	ll res = 0;

	while (left <= right)
	{
		ll mid = left + (right - left) / 2;

		if (check(arr, mid, n))
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	std::cout << res << std::endl;

	return 0;
}