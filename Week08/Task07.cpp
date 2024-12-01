#include <iostream>
#include <vector>

class Solution
{
public:
	int paintHouse(std::vector<std::vector<int>>& nums)
	{
		int dp[3]{ 0 };

		for (int i = 0; i < nums.size(); i++)
		{
			int dp0 = nums[i][0] + std::min(dp[1], dp[2]);
			int dp1 = nums[i][1] + std::min(dp[0], dp[2]);
			int dp2 = nums[i][2] + std::min(dp[0], dp[1]);

			dp[0] = dp0;
			dp[1] = dp1;
			dp[2] = dp2;
		}

		return std::min({ dp[0], dp[1], dp[2] });
	}
};

int main()
{
	Solution s;

	std::vector<std::vector<int>> nums{ { 17, 2, 17 }, {16, 16, 5 }, {14, 3, 19 } };

	std::cout << s.paintHouse(nums) << std::endl;
}