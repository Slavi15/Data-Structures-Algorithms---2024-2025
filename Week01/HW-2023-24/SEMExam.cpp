#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// https://www.hackerrank.com/contests/sda-hw-1-2023/challenges/challenge-4220/problem

constexpr size_t ALPHABET_SIZE = 26;
const char alphabetArray[ALPHABET_SIZE]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t N = 0;
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		size_t N, K;
		std::string data;

		std::cin >> N >> K >> data;

		size_t occurences[ALPHABET_SIZE]{ 0 };
		size_t len = data.size();

		for (size_t i = 0; i < len; i++)
		{
			if (data[i] >= 'A' && data[i] <= 'Z')
			{
				occurences[data[i] - 'A']++;
			}
		}

		for (size_t i = 0; i < ALPHABET_SIZE; i++)
		{
			if (occurences[i] >= K)
			{
				std::cout << alphabetArray[i];
			}
		}

		std::cout << std::endl;
	}

	return 0;
}