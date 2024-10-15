#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Student
{
	int points = 0;
	std::string name;

	Student(int points, const std::string& name) : points(points), name(name) {};

	friend bool operator<(const Student& lhs, const Student& rhs)
	{
		return lhs.points > rhs.points || (lhs.points == rhs.points && lhs.name.compare(rhs.name) <= 0);
	}
};

int main()
{
	size_t N = 0;
	std::cin >> N;

	std::vector<Student> arr;

	for (size_t i = 0; i < N; i++)
	{
		std::string name;
		std::cin >> name;

		Student s(0, name);

		arr.push_back(s);
	}

	for (size_t i = 0; i < N; i++)
	{
		int pts = 0;
		std::cin >> pts;
		arr[i].points = pts;
	}

	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < N; i++)
	{
		std::cout << arr[i].name << " " << arr[i].points << std::endl;
	}

	return 0;
}