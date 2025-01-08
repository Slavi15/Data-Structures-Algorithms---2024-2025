struct Edge
{
	int from;
	int to;
	int weight;

	friend bool operator<(const Edge& lhs, const Edge& rhs)
	{
		return lhs.weight > rhs.weight;
	}
};

int prims(int n, vector<vector<int>> edges, int start) {
	unordered_map<int, vector<Edge>> g;

	for (int i = 0; i < edges.size(); i++)
	{
		g[edges[i][0]].push_back({ edges[i][0], edges[i][1], edges[i][2] });
		g[edges[i][1]].push_back({ edges[i][1], edges[i][0], edges[i][2] });
	}

	std::vector<Edge> mstEdges;
	std::priority_queue<Edge> q;
	std::unordered_set<int> visited;

	q.push({ start, start, 0 });

	while (!q.empty() && visited.size() < n) {
		auto current = q.top();
		q.pop();

		if (visited.count(current.to)) continue;

		visited.insert(current.to);
		mstEdges.push_back(current);

		for (auto& adj : g[current.to]) {
			if (visited.count(adj.to)) continue;
			q.push(adj);
		}
	}

	int sum = 0;

	for (int i = 0; i < mstEdges.size(); i++)
		sum += mstEdges[i].weight;

	return sum;
}