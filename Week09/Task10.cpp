#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long

int main()
{
	ll N, M;
	std::cin >> N >> M;

	ll count = 0;

	std::vector<ll> arr(N);

	std::unordered_map<ll, ll> lhs;
	std::unordered_map<ll, ll> rhs;

	for (ll i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		rhs[arr[i]]++;
	}

	for (ll i = 0; i < N; i++)
	{
		rhs[arr[i]]--;

		if (arr[i] % M == 0)
		{
			count += lhs[arr[i] / M] * rhs[arr[i] * M];
		}

		lhs[arr[i]]++;
	}

	std::cout << count << std::endl;

	return 0;
}