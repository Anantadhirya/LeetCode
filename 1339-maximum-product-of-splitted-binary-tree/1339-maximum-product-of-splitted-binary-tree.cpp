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
    long long sm(TreeNode* cur) {
        if(!cur) return 0;
        return cur->val + sm(cur->left) + sm(cur->right);
    }
    long long solve(TreeNode* cur, long long &total, long long &ans) {
        if(!cur) return 0;
        long long sub = cur->val + solve(cur->left, total, ans) + solve(cur->right, total, ans);
        ans = max(ans, sub * (total - sub));
        return sub;
    }
    int maxProduct(TreeNode* root) {
        const long long MOD = 1e9 + 7;
        long long total = sm(root), ans = 0;
        solve(root, total, ans);
        return ans % MOD;
    }
};