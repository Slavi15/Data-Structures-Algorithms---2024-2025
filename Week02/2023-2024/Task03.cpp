#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

struct Weight
{
	size_t id = 0;
	size_t d = 0;
	size_t t = 0;
	double efficiency = 0;

	Weight(size_t id, size_t d, size_t t) : id(id), d(d), t(t)
	{
		this->efficiency = (double)(d * d) / t;
	};

	friend bool operator<(const Weight& lhs, const Weight& rhs)
	{
		return lhs.efficiency > rhs.efficiency || (std::abs(lhs.efficiency - rhs.efficiency) <= std::numeric_limits<double>::epsilon() && lhs.d > rhs.d);
	}
};

int main()
{
	size_t N = 0;
	std::cin >> N;

	std::vector<Weight> arr;

	for (size_t i = 0; i < N; i++)
	{
		size_t d, t;
		std::cin >> d >> t;

		Weight weight(i + 1, d, t);

		arr.push_back(weight);
	}

	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < N; i++)
	{
		std::cout << arr[i].id << " ";
	}

	return 0;
}