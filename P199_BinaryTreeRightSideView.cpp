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
    vector<int> rightSideView(TreeNode* root) {
        flags.resize(height(root));
        level(root, 1);
        return res;
    }
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void level(TreeNode* root, int lev) {
        if(!root) return;
        if(!flags[lev - 1]) {
            res.push_back(root->val);
            flags[lev - 1] = true;
        }
        level(root->right, lev + 1);
        level(root->left, lev + 1);
    }
private:
    vector<bool> flags;
    vector<int> res;
};
