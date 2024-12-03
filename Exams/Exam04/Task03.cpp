#include <iostream>
#include <vector>

bool canJump(const std::vector<int>& nums)
{
	int goal = nums.size() - 1;

	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if (i + nums[i] >= goal)
		{
			goal = i;
		}
	}

	return goal == 0;
}

int main()
{
	std::vector<int> nums{ 2, 3, 1, 1, 4 };

	std::cout << canJump(nums) << std::endl;

	return 0;
}