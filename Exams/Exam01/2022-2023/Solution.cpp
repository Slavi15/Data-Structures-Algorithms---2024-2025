#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Section
{
	size_t voters = 0;
	size_t id = 0;

	friend bool operator<(const Section& lhs, const Section& rhs)
	{
		return lhs.voters < rhs.voters || (lhs.voters == rhs.voters && lhs.id < rhs.id);
	}
};

int main() {
	size_t N = 0;
	std::cin >> N;

	std::vector<Section> arr;
	std::vector<Section> sorted(N);

	for (size_t i = 0; i < N; i++)
	{
		size_t voters = 0;
		std::cin >> voters;

		arr.push_back({ voters: voters, id : i });
	}

	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < N; i++)
	{
		sorted[arr[i].id].id = i;
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << sorted[i].id << " ";
	}

	return 0;
}