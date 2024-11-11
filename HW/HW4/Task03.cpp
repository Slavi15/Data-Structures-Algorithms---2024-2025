#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

#define ll long long
#define endl '\n'

int main()
{
	ll N = 0;
	std::cin >> N;

	std::vector<ll> arr(N);

	for (ll i = 0; i < N; i++)
		std::cin >> arr[i];

	std::stack<ll> st;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > 0)
		{
			st.push(arr[i]);
		}
		else
		{
			while (!st.empty() && st.top() > 0 && st.top() < std::abs(arr[i])) st.pop();

			if (!st.empty() && st.top() + arr[i] == 0)
			{
				st.pop();
			}
			else if (st.empty() || st.top() < 0)
			{
				st.push(arr[i]);
			}
		}
	}

	std::vector<ll> res;

	while (!st.empty())
	{
		res.push_back(st.top());
		st.pop();
	}

	for (int i = res.size() - 1; i >= 0; i--)
	{
		std::cout << res[i] << " ";
	}

	std::cout << endl;

	return 0;
}