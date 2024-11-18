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
	bool isSymmetricHelper(TreeNode* lhs, TreeNode* rhs)
	{
		if (!lhs || !rhs) return lhs == rhs;
		if (lhs->val != rhs->val) return false;

		return isSymmetricHelper(lhs->left, rhs->right) &&
			isSymmetricHelper(lhs->right, rhs->left);
	}

	bool isSymmetric(TreeNode* root)
	{
		if (!root) return true;
		return isSymmetricHelper(root->left, root->right);
	}
};