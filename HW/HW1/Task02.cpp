#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	size_t N = 0;
	std::cin >> N;

	std::vector<int> nums;

	int num = 0;
	std::cin >> num;

	nums.push_back(num);

	std::cout << nums[0] << std::endl;

	for (size_t i = 1; i < N; i++)
	{
		std::cin >> num;

		size_t idx = 0;

		for (size_t j = 0; j < i; j++)
		{
			if (num > nums[j])
			{
				idx++;
			}
		}

		nums.insert(nums.begin() + idx, num);

		size_t mid = nums.size() / 2;

		if (nums.size() % 2 == 0)
		{
			double median = (nums[mid] + nums[mid - 1]) / 2.0;
			std::cout << median << std::endl;
		}
		else
		{
			double median = nums[mid];
			std::cout << median << std::endl;
		}
	}

	return 0;
}