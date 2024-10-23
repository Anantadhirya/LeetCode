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
    vector<int> sm;
    void dfs(TreeNode* root, int level) {
        sm[level] += root->val;
        if(root->left) dfs(root->left, level+1);
        if(root->right) dfs(root->right, level+1);
    }
    void dfs2(TreeNode* root, int level) {
        int child = 0;
        if(root->left) child += root->left->val;
        if(root->right) child += root->right->val;
        if(root->left) {
            root->left->val = sm[level+1] - child;
            dfs2(root->left, level+1);
        }
        if(root->right) {
            root->right->val = sm[level+1] - child;
            dfs2(root->right, level+1);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        sm.assign(1e5, 0);
        dfs(root, 0);
        root->val = 0;
        dfs2(root, 0);
        return root;
    }
};