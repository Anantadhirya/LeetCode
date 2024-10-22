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
    void solve(TreeNode *root, vector<long long> &sm, int level = 0) {
        if(!root) return;
        if(level == sm.size()) sm.push_back(0);
        sm[level] += (long long)root->val;
        solve(root->left, sm, level+1);
        solve(root->right, sm, level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<long long> sm;
        solve(root, sm);
        sort(sm.begin(), sm.end());
        return k <= sm.size() ? sm[sm.size() - k] : -1;
    }
};