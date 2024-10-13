#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

constexpr size_t MAX_SIZE = 63;

int decode(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (ch - '0') + 1;
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		return (ch - 'a') + 11;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return (ch - 'A') + 37;
	}

	return -1;
}

char encode(int n)
{
	if (n >= 1 && n <= 10)
	{
		return (n - 1) + '0';
	}
	else if (n >= 11 && n <= 36)
	{
		return (n - 11) + 'a';
	}
	else if (n >= 37 && n <= 62)
	{
		return (n - 37) + 'A';
	}

	return 0;
}

int main()
{
	size_t occurences[MAX_SIZE]{ 0 };

	size_t N = 0;
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		char ch;
		std::cin >> ch;
		occurences[decode(ch)]++;
	}

	for (size_t i = 1; i < MAX_SIZE; i++)
	{
		for (size_t j = 0; j < occurences[i]; j++)
		{
			std::cout << encode(i);
		}
	}

	return 0;
}