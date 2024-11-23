#include <iostream>

struct Node
{
	int val = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int val) : val(val) {}
};

int getDepth(Node* root)
{
	if (!root) return 0;
	return 1 + std::max(getDepth(root->left), getDepth(root->right));
}

void depthHelper(Node* root, int depth)
{
	if (!root) return;

	depthHelper(root->left, depth + 1);
	depthHelper(root->right, depth + 1);

	int maximum = std::max(depth, std::max(getDepth(root->left), getDepth(root->right)));

	std::cout << maximum << " ";
}

void getMaximum(Node* root)
{
	if (!root) return;
	return depthHelper(root, 0);
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

		getMaximum(root);

		free(root);
	}

	return 0;
}