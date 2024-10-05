#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

size_t getOccurences()
{
	std::string str;
	size_t N = 0;
	char S;

	std::cin >> str >> N >> S;

	size_t strLength = str.length();
	size_t wordRepetitions = N / strLength;
	size_t leftCharacters = N % strLength;

	size_t occurences = 0;

	for (size_t i = 0; i < strLength; i++)
		if (str[i] == S) occurences++;

	occurences *= wordRepetitions;

	for (size_t i = 0; i < leftCharacters; i++)
		if (str[i] == S) occurences++;

	return occurences;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << getOccurences() << std::endl;

	return 0;
}