class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0;
		int left = 0;

		std::unordered_map<char, int> lastSeen;

		for (int right = 0; right < s.size(); right++)
		{
			char ch = s[right];

			if (lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= left)
			{
				left = lastSeen[ch] + 1;
			}

			maxLen = std::max(maxLen, right - left + 1);
			lastSeen[ch] = right;
		}

		return maxLen;
	}
};