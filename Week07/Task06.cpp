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
	std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
	{
		std::vector<std::vector<int>> toReturn;

		if (!root) return toReturn;

		std::queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			std::vector<int> row;

			for (int i = 0; i < size; ++i)
			{
				TreeNode* node = q.front();
				q.pop();
				row.push_back(node->val);

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}

			toReturn.insert(toReturn.begin(), row);
		}

		return toReturn;
	}
};