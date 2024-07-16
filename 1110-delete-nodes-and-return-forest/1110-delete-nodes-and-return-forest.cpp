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
    void dfs(TreeNode* curr, bool par, vector<TreeNode*> &ans, unordered_set<int> &s) {
        if(!curr) return;
        bool deleted = s.count(curr->val) ? 1 : 0;
        if(!par && !deleted) ans.push_back(curr);
        dfs(curr->left, !deleted, ans, s);
        dfs(curr->right, !deleted, ans, s);
        if(curr->left && s.count(curr->left->val)) curr->left = NULL;
        if(curr->right && s.count(curr->right->val)) curr->right = NULL;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        dfs(root, 0, ans, s);
        return ans;
    }
};