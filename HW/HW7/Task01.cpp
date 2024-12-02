#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main()
{
	int N, B;
	cin >> N >> B;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	unordered_map<int, int> m;
	int prefixSum = 0;
	int counter = 0;

	m[0] = 1;

	for (int i = 0; i < N; i++)
	{
		if (vec[i] == B)
		{
			prefixSum += N;
		}
		else
		{
			prefixSum += ((vec[i] > B) ? 1 : -1);
		}
		if (m.find(prefixSum - N) != m.end())
		{
			counter += m[prefixSum - N];
		}
		m[prefixSum]++;
	}

	cout << counter;

	return 0;
}