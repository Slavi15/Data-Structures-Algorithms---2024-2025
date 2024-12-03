class Solution
{
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
	{
		std::unordered_map<string, std::vector<std::string>> map;

		for (std::string str : strs)
		{
			std::string copy = str;
			std::sort(str.begin(), str.end());
			map[str].push_back(copy);
		}

		std::vector<std::vector<std::string>> res;

		for (auto& kv : map)
		{
			res.push_back(kv.second);
		}

		return res;
	}
};