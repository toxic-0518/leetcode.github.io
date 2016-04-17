/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* p = root;
        q.push(p);
        while(!q.empty()) {
            p = q.front();
            nodes.push_back(p);
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        
        for(int i = 1; i < nodes.size(); i *= 2) {
            for(int j = i - 1; j < (i - 1) * 2; j++) {
                nodes[j]->next = nodes[j+1];
            }
        }
    }
    
private:
    queue<TreeLinkNode*> q; 
    vector<TreeLinkNode*> nodes;
};
