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
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		if (!root1) return root2;
		if (!root2) return root1;

		TreeNode* toReturn = nullptr;

		if (root1 != nullptr && root2 != nullptr)
		{
			toReturn = new TreeNode(root1->val + root2->val);
			toReturn->left = mergeTrees(root1->left, root2->left);
			toReturn->right = mergeTrees(root1->right, root2->right);
		}
		else if (root1 == nullptr)
		{
			toReturn = new TreeNode(root2->val);
			toReturn->left = mergeTrees(root1, root2->left);
			toReturn->right = mergeTrees(root1, root2->right);
		}
		else if (root2 == nullptr)
		{
			toReturn = new TreeNode(root1->val);
			toReturn->left = mergeTrees(root1->left, root2);
			toReturn->right = mergeTrees(root1->right, root2);
		}

		return toReturn;
	}
};