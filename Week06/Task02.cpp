#include <iostream>
#include <string>
#include <queue>

void generateBinaryNumbers(int n)
{
	std::queue<std::string> q;
	q.push("1");

	while (!q.empty())
	{
		std::string curr = q.front();
		q.pop();

		if (std::stoi(curr, nullptr, 2) <= n)
		{
			std::cout << curr << " ";
		}
		else
		{
			break;
		}

		q.push(curr + "0");
		q.push(curr + "1");
	}
}

int main()
{
	generateBinaryNumbers(10);

	return 0;
}