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
class Solution {
public:
    void dfs(TreeNode* root, vector<int> &sm, int level) {
        if(sm.size() == level) sm.push_back(0);
        sm[level] += root->val;
        if(root->left) dfs(root->left, sm, level+1);
        if(root->right) dfs(root->right, sm, level+1);
    }
    void dfs2(TreeNode* root, vector<int> &sm, int level) {
        int child = 0;
        if(root->left) child += root->left->val;
        if(root->right) child += root->right->val;
        if(root->left) {
            root->left->val = sm[level+1] - child;
            dfs2(root->left, sm, level+1);
        }
        if(root->right) {
            root->right->val = sm[level+1] - child;
            dfs2(root->right, sm, level+1);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sm(1e5, 0);
        dfs(root, sm, 0);
        root->val = 0;
        dfs2(root, sm, 0);
        return root;
    }
};