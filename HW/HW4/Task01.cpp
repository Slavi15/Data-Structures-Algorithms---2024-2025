#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

constexpr size_t DIRECTIONS = 4;

int visited[1000][1000]{ 0 };

int xMovement[DIRECTIONS]{ -1, 0, 1, 0 };
int yMovement[DIRECTIONS]{ 0, 1, 0, -1 };

struct Point
{
	int x = 0;
	int y = 0;

	Point(int x, int y) : x(x), y(y) {}
};

bool isValid(int x, int y, int N, int M)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N = 0, M = 0, T = 0;
	std::cin >> N >> M >> T;

	std::queue<Point> q;

	int x = 0, y = 0, rottenApples = 0;

	while (std::cin >> x >> y)
	{
		if (!visited[--x][--y])
		{
			rottenApples++;
			q.push({ x, y });
			visited[x][y]++;
		}
	}

	while (T--)
	{
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			auto& currPoint = q.front();
			q.pop();

			for (int j = 0; j < DIRECTIONS; j++)
			{
				int newX = currPoint.x + xMovement[j];
				int newY = currPoint.y + yMovement[j];

				if (isValid(newX, newY, N, M) && !visited[newX][newY])
				{
					rottenApples++;
					q.push({ newX, newY });
					visited[newX][newY]++;
				}
			}
		}
	}

	int result = (N * M) - rottenApples;

	std::cout << result << std::endl;

	return 0;
}