#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

bool areEnough(int copies, int originals, int neededCopies, int neededOriginals)
{
	if (copies == neededCopies && originals == neededOriginals) return true;
	else if (copies <= 0 || copies > neededCopies) return false;

	return areEnough(copies + 2, originals, neededCopies, neededOriginals);
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	while (N--)
	{
		int copies, originals;
		std::cin >> copies >> originals;
		std::cout << (areEnough(originals - 1, originals, copies, originals) ? "yes" : "no") << std::endl;
	}

	return 0;
}