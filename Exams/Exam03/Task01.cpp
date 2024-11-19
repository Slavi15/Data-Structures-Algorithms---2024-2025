#include <iostream>
#include <vector>
#include <queue>

struct Node
{
	int val = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int val) : val(val) {}
};

void printBFS(Node* root)
{
	if (!root) return;

	std::queue<Node*> q;
	q.push(root);

	int idx = 1;

	while (!q.empty())
	{
		int size = q.size();

		std::vector<Node*> levelTree;

		for (int i = 0; i < size; i++)
		{
			auto currentNode = q.front();
			q.pop();

			if (currentNode->left) q.push(currentNode->left);
			if (currentNode->right) q.push(currentNode->right);

			levelTree.push_back(currentNode);
		}

		if (idx % 2 == 0)
		{
			for (int i = 0; i < levelTree.size(); i++)
			{
				std::cout << levelTree[i]->val << " ";
			}
		}
		else
		{
			for (int i = levelTree.size() - 1; i >= 0; i--)
			{
				std::cout << levelTree[i]->val << " ";
			}
		}

		idx++;

		for (int i = 0; i < levelTree.size(); i++)
		{
			delete levelTree[i];
		}
	}
}

int main()
{
	{
		Node* root = new Node(8);

		Node* lhs1 = new Node(3);
		Node* rhs1 = new Node(10);

		root->left = lhs1;
		root->right = rhs1;

		Node* lhs2 = new Node(1);
		Node* rhs2 = new Node(6);

		lhs1->left = nullptr;
		lhs1->right = nullptr;

		lhs1->left = lhs2;
		lhs1->right = rhs2;

		Node* lhs3 = new Node(4);
		Node* rhs3 = new Node(7);

		rhs2->left = lhs3;
		rhs2->right = rhs3;

		Node* rhs4 = new Node(14);

		rhs1->left = nullptr;
		rhs1->right = rhs4;

		Node* lhs4 = new Node(13);

		rhs4->left = lhs4;
		rhs4->right = nullptr;

		printBFS(root);
	}

	return 0;
}