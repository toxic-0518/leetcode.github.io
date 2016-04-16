/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // recursive version
 // using hasp_map to avoid repeated subproblem
class Solution {
public:
    int rob(TreeNode* root) {
        std::unordered_map<TreeNode*, int> hash_map;
        return robSub(root, hash_map);
    }
    
    int robSub(TreeNode* root, unordered_map<TreeNode*, int>& hash_map) {
        if(!root) return 0;
        if(hash_map.find(root) != hash_map.end()) return hash_map[root];
        int val = 0;
        if(root->left) {
            val += (robSub(root->left->left, hash_map) + robSub(root->left->right, hash_map));
        }
        if(root->right) {
            val += (robSub(root->right->left, hash_map) + robSub(root->right->right, hash_map));
        }
        int robMax = max(root->val + val, robSub(root->left, hash_map) + robSub(root->right, hash_map));
        hash_map[root] = robMax;
        return robMax;
    }
};
