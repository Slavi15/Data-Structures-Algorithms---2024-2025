struct Edge
{
	int to;
	double weight;
};

struct Node
{
	int idx;
	double prob;

	friend bool operator<(const Node& lhs, const Node& rhs)
	{
		return lhs.prob < rhs.prob;
	}
};

class Solution {
public:
	static double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
		unordered_map<int, vector<Edge>> g;

		for (int i = 0; i < edges.size(); i++)
		{
			g[edges[i][0]].push_back({ edges[i][1], succProb[i] });
			g[edges[i][1]].push_back({ edges[i][0], succProb[i] });
		}

		vector<double> distances(n, 0);
		distances[start_node] = 1;

		priority_queue<Node> q;
		q.push({ start_node, 1 });

		while (!q.empty())
		{
			auto currNode = q.top();
			q.pop();

			if (currNode.prob > distances[currNode.idx]) continue;

			for (auto& adj : g[currNode.idx])
			{
				double newProb = currNode.prob * adj.weight;
				if (newProb > distances[adj.to])
				{
					distances[adj.to] = newProb;
					q.push({ adj.to, newProb });
				}
			}
		}

		return distances[end_node] == 0 ? 0 : distances[end_node];
	}
};