#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersectArrays(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
	std::unordered_map<int, int> mp1;
	std::unordered_map<int, int> mp2;

	for (int i = 0; i < lhs.size(); i++)
	{
		mp1[lhs[i]]++;
	}

	for (int i = 0; i < rhs.size(); i++)
	{
		mp2[rhs[i]]++;
	}

	std::vector<int> result;

	for (auto& kv : mp1)
	{
		if (mp2.find(kv.first) != mp2.end())
		{
			int occurences = std::min(kv.second, mp2[kv.first]);

			for (int i = 0; i < occurences; i++)
			{
				result.push_back(kv.first);
			}
		}
	}

	return result;
}

int main()
{
	std::vector<int> lhs{ 4, 1, 2, 2, 5, 4 };
	std::vector<int> rhs{ 9, 4, 2, 8, 2 };

	std::vector<int> intersect = intersectArrays(lhs, rhs);

	for (int i = 0; i < intersect.size(); i++)
	{
		std::cout << intersect[i] << " ";
	}

	return 0;
}