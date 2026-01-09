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
    void getMaxDepth(TreeNode *cur, int &mx, int &cnt, int depth = 0) {
        if(!cur) return;
        if(depth > mx) mx = depth, cnt = 1;
        else if(depth == mx) cnt++;
        getMaxDepth(cur->left, mx, cnt, depth+1);
        getMaxDepth(cur->right, mx, cnt, depth+1);
    }
    int solve(TreeNode *cur, TreeNode* &ans, int &mx, int &cnt, int depth = 0) {
        if(!cur) return 0;
        int sub = 0;
        sub += solve(cur->left, ans, mx, cnt, depth+1);
        sub += solve(cur->right, ans, mx, cnt, depth+1);
        sub += (depth == mx);
        if(sub == cnt && !ans) ans = cur;
        return sub;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int mx = -1, cnt = 0;
        TreeNode* ans = NULL;
        getMaxDepth(root, mx, cnt);
        solve(root, ans, mx, cnt);
        return ans;
    }
};