#include <iostream>
#include <queue>
#include <unordered_map>

constexpr size_t MOVES = 8;

struct Point
{
	int x = 0;
	int y = 0;

	Point(int x, int y) : x(x), y(y) {}

	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}
};

struct PointHash
{
	size_t operator()(const Point& p) const
	{
		return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
	}
};

bool isValid(int x, int y)
{
	return x >= 0 && x < MOVES && y >= 0 && y < MOVES;
}

int minimumKnightMoves(int startX, int startY, int endX, int endY)
{
	int xMovеment[MOVES] = { 1, 1, -1, -1, 2, -2, 2, -2 };
	int yMovеment[MOVES] = { 2, -2, 2, -2, 1, 1, -1, -1 };

	std::queue<Point> q;
	std::unordered_map<Point, bool, PointHash> uMap;

	int minMoves = 0;

	Point startPoint(startX, startY);

	q.push(startPoint);
	uMap[startPoint] = true;

	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			auto& currPosition = q.front();
			q.pop();

			if (currPosition.x == endX && currPosition.y == endY) return minMoves;

			for (int j = 0; j < MOVES; j++)
			{
				int newX = currPosition.x + xMovеment[j];
				int newY = currPosition.y + yMovеment[j];

				Point newPoint(newX, newY);

				if (isValid(newX, newY) && uMap.find(newPoint) == uMap.end())
				{
					uMap[newPoint] = true;
					q.push(newPoint);
				}
			}
		}

		minMoves++;
	}

	return -1;
}

int main()
{
	std::cout << minimumKnightMoves(0, 0, 2, 1) << std::endl;
	std::cout << minimumKnightMoves(0, 0, 7, 7) << std::endl;

	return 0;
}