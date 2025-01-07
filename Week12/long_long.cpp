https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long/

#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

#define ll long long

struct Edge
{
	ll to;
	ll weight;
};

struct Node
{
	ll idx;
	ll dist;

	friend bool operator<(const Node& lhs, const Node& rhs)
	{
		return lhs.dist < rhs.dist;
	}
};

vector<int> dijkstra(int U, int nodes, unordered_map<int, vector<Edge>> g)
{
	vector<int> dists(nodes + 1, INT_MIN);
	dists[U] = 0;

	priority_queue<Node> q;
	q.push({ U, 0 });

	while (!q.empty())
	{
		auto currNode = q.top();
		q.pop();

		if (currNode.dist < dists[currNode.idx]) continue;

		for (auto& adj : g[currNode.idx])
		{
			int newDist = currNode.dist + adj.weight;
			if (newDist > dists[adj.to])
			{
				dists[adj.to] = newDist;
				q.push({ adj.to, newDist });
			}
		}
	}

	return dists;
}

int main()
{
	ll n, m, s, t;
	cin >> n >> m >> s >> t;

	unordered_map<int, vector<Edge>> g;

	for (ll i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
	}

	vector<int> dists = dijkstra(s, n, g);

	if (dists[t] == INT_MIN)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dists[t] << endl;
	}

	return 0;
}
