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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preorder(root, pre);
        return pre;
    }
    void preorder(TreeNode* root, vector<int>& v) {
        if(root) {
            v.push_back(root->val);
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }
};
