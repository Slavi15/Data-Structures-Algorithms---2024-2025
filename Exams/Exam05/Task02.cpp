#include <iostream>
#include <vector>
#include <unordered_map>

int getDistance(int u, int v, std::unordered_map<int, std::unordered_map<int, int>> g)
{
	if (g.find(u) == g.end())
	{
		return -1;
	}
	else
	{
		if (g[u].find(v) == g[u].end())
		{
			return -1;
		}
		else
		{
			return g[u][v];
		}
	}

	return -1;
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::unordered_map<int, std::unordered_map<int, int>> g;

	int x, y, w;

	for (int i = 0; i < M; i++)
	{
		std::cin >> x >> y >> w;

		if (g[x].count(y) == 0) g[x][y] = INT_MAX;

		g[x][y] = std::min(g[x][y], w);
	}

	int u, v;
	std::cin >> u >> v;

	std::cout << getDistance(u, v, g) << std::endl;

	return 0;
}