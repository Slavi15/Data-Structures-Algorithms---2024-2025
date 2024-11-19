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

		getMaximum(root);
	}

	return 0;
}