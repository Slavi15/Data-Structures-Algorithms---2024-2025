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

		std::vector<int> levelTree;

		for (int i = 0; i < size; i++)
		{
			auto currentNode = q.front();
			q.pop();

			if (currentNode->left) q.push(currentNode->left);
			if (currentNode->right) q.push(currentNode->right);

			levelTree.push_back(currentNode->val);
		}

		if (idx % 2 == 0)
		{
			for (int i = 0; i < levelTree.size(); i++)
			{
				std::cout << levelTree[i] << " ";
			}
		}
		else
		{
			for (int i = levelTree.size() - 1; i >= 0; i--)
			{
				std::cout << levelTree[i] << " ";
			}
		}

		idx++;
	}
}

Node* insertNode(Node* root, int value)
{
	if (!root)
	{
		return new Node(value);
	}

	if (value < root->val)
	{
		root->left = insertNode(root->left, value);
	}
	else if (value > root->val)
	{
		root->right = insertNode(root->right, value);
	}

	return root;
}

void free(Node* root)
{
	if (!root) return;

	free(root->left);
	free(root->right);

	delete root;
}

int main()
{
	{
		Node* root = new Node(8);

		root = insertNode(root, 3);
		root = insertNode(root, 10);
		root = insertNode(root, 1);
		root = insertNode(root, 6);
		root = insertNode(root, 4);
		root = insertNode(root, 7);
		root = insertNode(root, 14);
		root = insertNode(root, 13);

		printBFS(root);

		free(root);
	}

	return 0;
}