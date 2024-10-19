#include <iostream>
#include <unordered_map>

class Solution
{
public:
	char findTheDifference(std::string s, std::string t)
	{
		std::unordered_map<char, int> uMap;
		char uniqueCharacter;

		for (char ch : s) uMap[ch]++;

		for (char ch : t)
		{
			if (uMap[ch] == 0)
			{
				uniqueCharacter = ch;
			}
			else
			{
				uMap[ch]--;
			}
		}

		return uniqueCharacter;
	}
};