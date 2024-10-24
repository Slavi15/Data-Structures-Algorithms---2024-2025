#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

bool check(std::vector<ll>& skills, ll target, ll teamsCount)
{
	ll currentSum = 0;
	ll teamsFormed = 1;

	for (ll i = 0; i < skills.size(); i++)
	{
		if (skills[i] > target) return false;

		currentSum += skills[i];

		if (currentSum > target)
		{
			teamsFormed++;
			currentSum = skills[i];
		}
	}

	return teamsFormed <= teamsCount;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll N, T;
	std::cin >> N >> T;

	std::vector<ll> skills(N);

	ll sum = 0;
	ll max = 0;

	for (ll i = 0; i < N; i++)
	{
		std::cin >> skills[i];
		sum += skills[i];
		if (skills[i] > max) max = skills[i];
	}

	ll left = max;
	ll right = sum;
	ll result = 0;

	while (left <= right)
	{
		ll mid = left + (right - left) / 2;

		if (check(skills, mid, T))
		{
			result = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	std::cout << result;

	return 0;
}