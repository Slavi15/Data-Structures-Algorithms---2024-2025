#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

ll getDepth(ll left, ll right, ll current, ll depth)
{
	if (left >= right) return depth;

	ll mid1 = left + (right - left) / 3;
	ll mid2 = right - (right - left) / 3;

	if (current <= mid1)
	{
		return getDepth(left, mid1, current, depth + 1);
	}
	else if (current >= mid2)
	{
		return getDepth(mid2, right, current, depth + 1);
	}
	else
	{
		return depth;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll P, N;
	std::cin >> P >> N;

	ll maxFriends = std::pow(3, P);

	for (ll i = 0; i < N; i++)
	{
		ll current = 0;
		std::cin >> current;
		std::cout << getDepth(1, maxFriends, current, 1) << std::endl;
	}

	return 0;
}