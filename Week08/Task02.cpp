class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, INT_MAX));
		dp[rows][cols - 1] = 0;

		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = cols - 1; j >= 0; j--)
			{
				dp[i][j] = grid[i][j] + std::min(grid[i + 1][j], grid[i][j + 1]);
			}
		}

		return dp[0][0];
	}
};