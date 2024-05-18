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
    void solve(TreeNode *root, int &cnt, int &coin, int &ans) {
        if(!root) return;
        int curr_cnt = 0, curr_coin = 0;
        solve(root->left, curr_cnt, curr_coin, ans);
        solve(root->right, curr_cnt, curr_coin, ans);
        curr_cnt++;
        curr_coin += root->val;
        ans += abs(curr_cnt - curr_coin);
        cnt += curr_cnt;
        coin += curr_coin;
    }
    int distributeCoins(TreeNode* root) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int cnt = -1, coin = -1, ans = 0;
        solve(root, cnt, coin, ans);
        return ans;
    }
};