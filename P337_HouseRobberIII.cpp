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

// using arry to record two condition
// condition 0: not rob root
// condition 1: rob root
class Solution {
public:
    int rob(TreeNode* root) {
        int *res = robSub(root);
        return max(res[0], res[1]);
    }
    
    int* robSub(TreeNode* root) {
        int *res = new int [2];
        res[0] = 0;
        res[1] = 0;
        if(!root) return res;
        int *lc = robSub(root->left);
        int *rc = robSub(root->right);
        res[0] = max(lc[0], lc[1]) + max(rc[0], rc[1]);
        res[1] = root->val + lc[0] + rc[0];
        return res;
    } 
};
