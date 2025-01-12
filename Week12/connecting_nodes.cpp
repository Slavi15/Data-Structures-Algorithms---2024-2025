#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct DJS
{
	int n;
	vector<int> parents;
	vector<int> sizes;

	DJS(int n) : n(n), parents(n + 1), sizes(n + 1, 1)
	{
		for (int i = 0; i <= n; i++)
		{
			parents[i] = i;
		}
	}

	int findParent(int n)
	{
		if (parents[n] == n)
		{
			return n;
		}

		return parents[n] = findParent(parents[n]);
	}

	void unify(int x, int y)
	{
		int px = findParent(x);
		int py = findParent(y);

		if (px == py)
		{
			return;
		}

		if (sizes[px] > sizes[py])
		{
			parents[py] = px;
			sizes[px] += sizes[py];
			n--;
		}
		else
		{
			parents[px] = py;
			sizes[py] += sizes[px];
			n--;
		}
	}
};

struct Edge
{
	int x;
	int y;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<Edge> edges;

	int N = 0;
	cin >> N;

	int x, y;

	while (cin >> x >> y)
	{
		edges.push_back({ x, y });
	}

	DJS djs(N);

	for (size_t i = 0; i < edges.size(); i++)
	{
		int x = edges[i].x;
		int y = edges[i].y;

		if (djs.findParent(x) != djs.findParent(y))
		{
			djs.unify(x, y);
			cout << djs.n << endl;
		}
		else
		{
			cout << djs.n << " CYCLE FORMED!" << endl;
		}
	}

	return 0;
}