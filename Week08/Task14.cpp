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
	std::vector<int> dfs(TreeNode* root)
	{
		if (!root) return { 0, 0 };

		std::vector<int> lhs = dfs(root->left);
		std::vector<int> rhs = dfs(root->right);

		int withRoot = root->val + lhs[1] + rhs[1];
		int withoutRoot = std::max(lhs[0], lhs[1]) + std::max(rhs[0], rhs[1]);

		return { withRoot, withoutRoot };
	}

	int rob(TreeNode* root) {
		std::vector<int> res = dfs(root);
		return std::max(res[0], res[1]);
	}
};