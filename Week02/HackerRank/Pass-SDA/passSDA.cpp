#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long

int main()
{
	LL M, N;
	std::cin >> M >> N;

	std::vector<LL> arr;

	LL negativeMark = 0;

	for (LL i = 0; i < N; i++)
	{
		LL num = 0;
		std::cin >> num;

		if (num < 0)
		{
			negativeMark = num;
		}
		else
		{
			arr.push_back(num);
		}
	}

	for (LL i = 0; i < arr.size(); i++)
	{
		if (arr[i] > M)
		{
			negativeMark += arr[i] - M;
		}
	}

	std::cout << (negativeMark >= M ? "yes" : "no") << std::endl;

	return 0;
}