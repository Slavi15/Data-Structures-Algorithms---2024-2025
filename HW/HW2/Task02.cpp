#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	size_t N, Q;
	std::cin >> N >> Q;

	std::vector<int> arr(N);

	for (size_t i = 0; i < N; i++)
		std::cin >> arr[i];

	std::sort(arr.begin(), arr.end());

	while (Q--)
	{
		size_t min, max;
		std::cin >> min >> max;

		if (min > max)
		{
			std::cout << 0 << std::endl;
			continue;
		}

		auto low = std::lower_bound(arr.begin(), arr.end(), min);
		auto high = std::upper_bound(arr.begin(), arr.end(), max);

		int count = high - low;
		std::cout << count << std::endl;
	}

	return 0;
}