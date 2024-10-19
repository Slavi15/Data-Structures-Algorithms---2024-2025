#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

struct Section
{
	int id;
	int voters;

	friend bool operator<(const Section& lhs, const Section& rhs)
	{
		return lhs.voters < rhs.voters || (lhs.voters == rhs.voters && lhs.id < rhs.id);
	}
};

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<Section> arr;
	for (int i = 0; i < N; i++)
	{
		int voters;
		std::cin >> voters;
		arr.push_back({ id: i, voters : voters });
	}

	std::sort(arr.begin(), arr.end());

	std::vector<Section> sorted(N);

	for (int i = 0; i < N; i++)
	{
		sorted[arr[i].id].id = i;
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << sorted[i].id << " ";
	}

	return 0;
}