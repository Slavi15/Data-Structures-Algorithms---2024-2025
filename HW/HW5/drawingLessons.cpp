#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

struct Node
{
	ll data = 0;

	ll leftCount = 0;
	ll rightCount = 0;

	Node* left = nullptr;
	Node* right = nullptr;
};

constexpr size_t SIZE = 1e6;

Node nodes[SIZE];

void fillCounts(Node* root)
{
	if (!root->left)
	{
		root->leftCount = 0;
	}
	else
	{
		fillCounts(root->left);
		root->leftCount = root->left->leftCount + root->left->rightCount + 1;
	}

	if (!root->right)
	{
		root->rightCount = 0;
	}
	else
	{
		fillCounts(root->right);
		root->rightCount = root->right->leftCount + root->right->rightCount + 1;
	}
}

ll getMaxScore(Node* root, ll score)
{
	ll currCount = 1;

	if (score != 0) currCount *= score;

	if (root->leftCount != 0) currCount *= root->leftCount;

	if (root->rightCount != 0) currCount *= root->rightCount;

	if (root->left)
		currCount = std::max(currCount, getMaxScore(root->left, score + 1 + root->rightCount));

	if (root->right)
		currCount = std::max(currCount, getMaxScore(root->right, score + 1 + root->leftCount));

	return currCount;
}

ll getMaxScore(Node* root)
{
	if (!root || (root->leftCount + root->rightCount) == 0) return 0;

	return getMaxScore(root, 0);
}

int main()
{
	ll N = 0;
	std::cin >> N;

	for (ll i = 0; i < N; i++)
	{
		ll left, right;
		std::cin >> left >> right;

		nodes[i].data = i;

		if (left != -1) nodes[i].left = &nodes[left];

		if (right != -1) nodes[i].right = &nodes[right];
	}

	fillCounts(&nodes[0]);

	std::cout << getMaxScore(&nodes[0]) << std::endl;

	return 0;
}