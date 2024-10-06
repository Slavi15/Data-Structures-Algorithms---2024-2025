#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Symbol
{
	int index = -1;
	size_t counter = 0;

	friend bool operator<(const Symbol& lhs, const Symbol& rhs)
	{
		return lhs.index < rhs.index;
	}
};

int main() {
	std::string str;
	std::cin >> str;

	std::vector<Symbol> arr(256);

	size_t len = str.size();

	for (size_t i = 0; i < len; i++)
	{
		arr[str[i]].counter++;
		if (arr[str[i]].index == -1) arr[str[i]].index = i;
	}

	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < 256; i++)
	{
		if (arr[i].counter == 1)
		{
			std::cout << arr[i].index << " ";
		}
	}

	return 0;
}