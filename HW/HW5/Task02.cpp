#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
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

bool isBST(Node* root, ll min, ll max)
{
	if (!root) return true;

	if (root->val <= min || root->val >= max) return false;

	return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

void buildTree(Node* nodes[])
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
}

int main()
{
	ll T = 0;
	std::cin >> T;

	while (T--)
	{
		Node* nodes[SIZE]{ };

		buildTree(nodes);

		std::cout << isBST(nodes[0], LLONG_MIN, LLONG_MAX) << std::endl;
	}

	return 0;
}