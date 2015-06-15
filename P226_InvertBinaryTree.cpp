/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	static void inverse(TreeNode* root) {
		if (root->left)
			inverse(root->left);
		if (root->right)
			inverse(root->right);
		TreeNode *temp = root->right;
		root->right = root->left;
		root->left = temp;
	}
	TreeNode* invertTree(TreeNode* root) {
	    if(!root) return nullptr;
		inverse(root);
		return root;
	}
};
