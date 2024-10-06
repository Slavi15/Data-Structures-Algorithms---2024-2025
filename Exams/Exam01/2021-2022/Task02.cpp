#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Team
{
	size_t id = 0;
	double xi = 0;
	double yi = 0;

	Team(size_t id, double xi, double yi) : id(id), xi(xi), yi(yi) {};

	double getPoints() const
	{
		return xi * xi / yi;
	}

	friend bool operator<(const Team& lhs, const Team& rhs)
	{
		return lhs.getPoints() > rhs.getPoints() ||
			(lhs.getPoints() == rhs.getPoints() && lhs.xi > rhs.xi);
	}
};

int main() {
	size_t N = 0;
	std::cin >> N;

	std::vector<Team> arr;

	for (size_t i = 0; i < N; i++)
	{
		double xi, yi;
		std::cin >> xi >> yi;

		Team t(i + 1, xi, yi);

		arr.push_back(t);
	}

	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < N; i++)
	{
		std::cout << arr[i].id << " ";
	}

	return 0;
}