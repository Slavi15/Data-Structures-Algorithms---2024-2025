class Solution
{
public:
	double findMaxAverage(vector<int>& nums, int k)
	{
		double sum = 0, maxAverage = 0;

		for (int i = 0; i < k; i++)
		{
			sum += nums[i];
		}

		maxAverage = sum;

		for (int i = k; i < nums.size(); i++)
		{
			sum += nums[i] - nums[i - k];
			maxAverage = std::max(maxAverage, sum);
		}

		return maxAverage / k;
	}
};