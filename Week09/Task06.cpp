class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		std::unordered_map<std::string, int> uMap;

		for (int i = 0; i < s.size(); i++)
		{
			std::string sub = s.substr(i, 10);

			if (sub.size() == 10)
			{
				uMap[sub]++;
			}
		}

		std::vector<std::string> res;

		for (auto& kv : uMap)
		{
			if (kv.second > 1)
			{
				res.push_back(kv.first);
			}
		}

		return res;
	}
};