#define ll long long

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		ll rows = obstacleGrid.size();
		ll cols = obstacleGrid[0].size();

		std::vector<std::vector<ll>> dp(rows + 1, std::vector<ll>(cols + 1, 0));
		dp[rows][cols - 1] = 1;

		for (ll i = rows - 1; i >= 0; i--)
		{
			for (ll j = cols - 1; j >= 0; j--)
			{
				if (!obstacleGrid[i][j])
				{
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
				}
			}
		}

		return dp[0][0];
	}
};