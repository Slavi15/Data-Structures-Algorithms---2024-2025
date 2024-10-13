#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long

int main()
{
	LL N = 0;
	std::cin >> N;

	std::vector<int> arr;

	for (LL i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		arr.push_back(num);
	}

	LL left = 0, right = N - 1;

	while (left < N - 1 && arr[left] <= arr[left + 1]) left++;
	while (right > 0 && arr[right] >= arr[right - 1]) right--;

	if (left >= right)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	int minEl = arr[left], maxEl = arr[right];

	for (LL i = left; i <= right; i++)
	{
		minEl = std::min(minEl, arr[i]);
		maxEl = std::max(maxEl, arr[i]);
	}

	while (left >= 0 && arr[left] > minEl) left--;
	while (right <= N - 1 && arr[right] < maxEl) right++;

	LL result = right - left - 1;

	std::cout << result << std::endl;

	return 0;
}