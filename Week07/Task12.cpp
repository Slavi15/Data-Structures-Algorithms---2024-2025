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
	int diff = INT_MAX;
	TreeNode* node = nullptr;

	void dfs(TreeNode* root)
	{
		if (!root) return;

		if (root->left) dfs(root->left);

		if (node) diff = std::min(diff, std::abs(node->val - root->val));
		node = root;

		if (root->right) dfs(root->right);
	}

	int getMinimumDifference(TreeNode* root)
	{
		dfs(root);
		return diff;
	}
};