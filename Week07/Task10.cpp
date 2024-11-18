/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
	int pos = 0;

	TreeNode* inOrder(TreeNode* root, int k)
	{
		if (!root) return nullptr;

		TreeNode* lhs = inOrder(root->left, k);
		if (lhs) return lhs;

		pos++;
		if (pos == k) return root;

		return inOrder(root->right, k);
	}

	int kthSmallest(TreeNode* root, int k)
	{
		TreeNode* node = inOrder(root, k);
		if (!node) return -1;
		return node->val;
	}
};