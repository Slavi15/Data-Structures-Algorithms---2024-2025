class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		std::vector<int> dp(n + 1, 0);

		for (int i = 2; i <= n; i++)
		{
			dp[i] = std::min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
		}

		return dp[n];
	}
};