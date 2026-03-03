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
    int dfs(TreeNode *cur, int &n, int &x, bool &ret) {
        if(!cur) return 0;
        int l = dfs(cur->left, n, x, ret);
        int r = dfs(cur->right, n, x, ret);
        int sz = 1 + l + r;
        if(cur->val == x) {
            if(n - sz >= sz) ret = 1;
            if(l >= n - l) ret = 1;
            if(r >= n - r) ret = 1;
        }
        return sz;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        bool ret = 0;
        dfs(root, n, x, ret);
        return ret;
    }
};