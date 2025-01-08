struct Node {
	int x;
	int y;
	int removed;

	friend bool operator<(const Node& lhs, const Node& rhs)
	{
		return lhs.removed > rhs.removed;
	}
};

vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

class Solution {
private:
	bool isValid(int x, int y, int rows, int cols) {
		return x >= 0 && x < rows && y >= 0 && y < cols;
	}

public:
	int minimumObstacles(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		vector<vector<int>> minObstacles(rows, vector<int>(cols, INT_MAX));
		priority_queue<Node> q;

		q.push({ 0, 0, 0 });
		minObstacles[0][0] = 0;

		while (!q.empty()) {
			auto current = q.top();
			q.pop();

			if (minObstacles[current.x][current.y] < current.removed) {
				continue;
			}

			// early exit
			if (current.x == rows - 1 && current.y == cols - 1) {
				return current.removed;
			}

			for (int i = 0; i < 4; i++) {
				int newX = current.x + directions[i][0];
				int newY = current.y + directions[i][1];

				if (isValid(newX, newY, rows, cols)) {
					int newRemoved = current.removed + grid[newX][newY];

					if (minObstacles[newX][newY] > newRemoved) {
						minObstacles[newX][newY] = newRemoved;
						q.push({ newX, newY, newRemoved });
					}
				}
			}
		}

		return 0;
	}
};