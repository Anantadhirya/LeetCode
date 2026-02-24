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
    void dfs(TreeNode *cur, int val, int &ans) {
        if(!cur) return;
        val = 2*val + cur->val;
        if(!cur->left && !cur->right) ans += val;
        dfs(cur->left, val, ans);
        dfs(cur->right, val, ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};