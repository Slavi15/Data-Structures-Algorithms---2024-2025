#include <iostream>
#include <unordered_map>

int main()
{
	int currentNum = 0;
	int maxOccurences = 0;
	int num = 0;

	std::unordered_map<int, int> mp;

	while (true)
	{
		std::cin >> num;

		if (num == -1) break;

		if (num == 0)
		{
			std::cout << currentNum << " ";
			mp[currentNum] = 0;
			maxOccurences = 0;

			for (auto& kv : mp)
			{
				if (kv.second > maxOccurences)
				{
					maxOccurences = kv.second;
					currentNum = kv.first;
				}
				else if (kv.second == maxOccurences)
				{
					currentNum = std::min(currentNum, kv.first);
				}
			}
		}
		else
		{
			mp[num]++;

			if (mp[num] > maxOccurences)
			{
				maxOccurences = mp[num];
				currentNum = num;
			}
			else if (mp[num] == maxOccurences)
			{
				currentNum = std::min(currentNum, num);
			}
		}
	}

	return 0;
}