struct Point
{
	int x;
	int y;

	friend bool operator==(const Point& lhs, const Point& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
};

struct PointHash {
	size_t operator()(const Point& p) const {
		size_t h1 = std::hash<int>{}(p.x);
		size_t h2 = std::hash<int>{}(p.y);

		return h1 ^ (h2 << 1);
	}
};

struct Edge
{
	Point from;
	Point to;
	int weight;

	friend bool operator<(const Edge& lhs, const Edge& rhs)
	{
		return lhs.weight > rhs.weight;
	}
};

class Solution {
private:
	int getDistance(const Point& p1, const Point& p2)
	{
		return abs(p1.x - p2.x) + abs(p1.y - p2.y);
	}

	unordered_map<Point, vector<Edge>, PointHash> getGraph(vector<vector<int>>& points)
	{
		unordered_map<Point, vector<Edge>, PointHash> g;

		for (int i = 0; i < points.size(); i++)
		{
			for (int j = 0; j < points.size(); j++)
			{
				if (i != j)
				{
					Point first(points[i][0], points[i][1]);
					Point second(points[j][0], points[j][1]);

					int dist = getDistance(first, second);

					g[first].push_back({ first, second, dist });
					g[second].push_back({ second, first, dist });
				}
			}
		}

		return g;
	}

public:
	int minCostConnectPoints(vector<vector<int>>& points)
	{
		unordered_map<Point, vector<Edge>, PointHash> g = getGraph(points);

		vector<Edge> mstEdges;
		unordered_set<Point, PointHash> visited;
		priority_queue<Edge> q;

		Point point(points[0][0], points[0][1]);
		q.push({ point, point, 0 });

		while (!q.empty() && visited.size() < points.size())
		{
			auto current = q.top();
			q.pop();

			if (visited.count(current.to)) continue;

			mstEdges.push_back(current);
			visited.insert(current.to);

			for (auto& adj : g[current.to])
			{
				if (visited.count(adj.to)) continue;
				q.push(adj);
			}
		}

		int sum = 0;

		for (int i = 0; i < mstEdges.size(); i++)
		{
			sum += mstEdges[i].weight;
		}

		return sum;
	}
};