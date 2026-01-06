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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        TreeNode *cur;
        q.push(cloned);
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(cur->val == target->val) return cur;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return NULL;
    }
};