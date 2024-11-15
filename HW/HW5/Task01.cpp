#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

constexpr size_t SIZE = 1e6 + 1;

struct Node
{
	ll val = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(ll val) : val(val) {}
};

Node* nodes[SIZE]{ };

std::map<ll, ll> mp;

void recurseNodes(Node* root, int dist)
{
	mp[dist] += root->val;
	if (root->left) recurseNodes(root->left, dist - 1);
	if (root->right) recurseNodes(root->right, dist + 1);
}

int main()
{
	ll N = 0;
	std::cin >> N;

	for (ll i = 0; i < N; i++)
	{
		ll val, lhs, rhs;
		std::cin >> val >> lhs >> rhs;

		if (!nodes[i])
		{
			nodes[i] = new Node(val);
		}
		else
		{
			nodes[i]->val = val;
		}

		if (lhs != -1)
		{
			if (!nodes[lhs])
			{
				nodes[lhs] = new Node(0);
			}

			nodes[i]->left = nodes[lhs];
		}

		if (rhs != -1)
		{
			if (!nodes[rhs])
			{
				nodes[rhs] = new Node(0);
			}

			nodes[i]->right = nodes[rhs];
		}
	}

	recurseNodes(nodes[0], 0);

	for (auto& kv : mp)
	{
		std::cout << kv.second << " ";
	}

	return 0;
}