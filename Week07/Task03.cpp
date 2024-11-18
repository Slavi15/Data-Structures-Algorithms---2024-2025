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
	int minDepth(TreeNode* root)
	{
		if (!root) return 0;

		int minDepth = 0;

		std::queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			minDepth++;
			int size = q.size();

			for (int i = 0; i < size; i++)
			{
				TreeNode* currNode = q.front();
				q.pop();

				if (!currNode->left && !currNode->right) return minDepth;

				if (currNode->left) q.push(currNode->left);
				if (currNode->right) q.push(currNode->right);
			}
		}

		return minDepth;
	}
};