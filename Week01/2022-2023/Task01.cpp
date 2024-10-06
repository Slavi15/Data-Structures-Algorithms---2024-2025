#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

size_t solve()
{
	size_t len = 0;
	std::string list;

	std::cin >> len >> list;

	size_t count = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (list[i] == list[i - 1])
		{
			count++;
		}
	}

	return count;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();

	size_t Q = 0;
	std::cin >> Q;

	for (size_t i = 0; i < Q; i++)
	{
		std::cout << solve() << std::endl;
	}

	return 0;
}