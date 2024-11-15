#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

constexpr size_t SIZE = 1e6 + 1;

struct Node
{
	int timeIn = 0;
	int timeOut = 0;
	std::vector<int> children;
};

Node nodes[SIZE]{ };
int timer = 0;

void dfs(int curr)
{
	nodes[curr].timeIn = timer++;

	for (auto& child : nodes[curr].children) dfs(child);

	nodes[curr].timeOut = timer++;
}

bool isAncestor(int x, int y)
{
	return nodes[x].timeIn < nodes[y].timeIn && nodes[y].timeOut < nodes[x].timeOut;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N = 0;
	std::cin >> N;

	int edges = N - 1;

	int a, b;
	std::cin >> a >> b;

	nodes[a].children.push_back(b);

	int root = a;

	for (int i = 1; i < edges; i++)
	{
		std::cin >> a >> b;
		nodes[a].children.push_back(b);
	}

	dfs(root);

	int Q = 0;
	std::cin >> Q;

	while (Q--)
	{
		int x, y;
		std::cin >> x >> y;
		std::cout << (isAncestor(x, y) ? "YES\n" : "NO\n");
	}

	return 0;
}