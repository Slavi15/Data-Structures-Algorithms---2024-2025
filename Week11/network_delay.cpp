https://leetcode.com/problems/network-delay-time/

struct Edge
{
	int to;
	int weight;
};

struct Node
{
	int idx;
	int dist;

	friend bool operator<(const Node& lhs, const Node& rhs)
	{
		return lhs.dist < rhs.dist;
	}
};

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		unordered_map<int, vector<Edge>> g;

		for (int i = 0; i < times.size(); i++)
		{
			g[times[i][0]].push_back({ times[i][1], times[i][2] });
			// g[times[i][1]].push_back({ times[i][0], times[i][2] });
			// graph is directed
		}

		vector<int> distances(n + 1, INT_MAX);
		distances[k] = 0;

		priority_queue<Node> q;
		q.push({ k, 0 });

		while (!q.empty())
		{
			auto currNode = q.top();
			q.pop();

			if (currNode.dist > distances[currNode.idx]) continue;

			for (auto& adj : g[currNode.idx])
			{
				int newDist = currNode.dist + adj.weight;
				if (newDist < distances[adj.to])
				{
					distances[adj.to] = newDist;
					q.push({ adj.to, newDist });
				}
			}
		}

		for (int i = 1; i < distances.size(); i++)
		{
			if (distances[i] == INT_MAX) return -1;
		}

		return *max_element(distances.begin() + 1, distances.end());
	}
};