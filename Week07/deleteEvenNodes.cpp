#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct TreeNode
{
	int val = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	TreeNode(int val) : val(val) {}
};

TreeNode* deleteNode(TreeNode* root, int key);

void free(TreeNode* root)
{
	if (!root) return;

	free(root->left);
	free(root->right);

	delete root;
}

TreeNode* findMin(TreeNode* root)
{
	if (!root->left) return root;
	return findMin(root->left);
}

TreeNode* removeRoot(TreeNode* root)
{
	if (!root->left)
	{
		TreeNode* temp = root->right;
		delete root;
		return temp;
	}
	else if (!root->right)
	{
		TreeNode* temp = root->left;
		delete root;
		return temp;
	}

	TreeNode* temp = findMin(root->right);
	root->val = temp->val;
	root->right = deleteNode(root->right, temp->val);

	return root;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
	if (!root) return nullptr;

	if (root->val % key == 0)
	{
		return removeRoot(root);
	}
	else
	{
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
	}

	return root;
}

void printTree(TreeNode* root)
{
	if (!root) return;

	std::cout << root->val << " ";

	printTree(root->left);
	printTree(root->right);
}

int main()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* node1 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(6);
	TreeNode* node3 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->right = node5;

	printTree(root);

	std::cout << std::endl;

	deleteNode(root, 2); // 2, because we are deleting even nodes

	printTree(root);

	free(root);

	return 0;
}