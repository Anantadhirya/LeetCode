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
    int n = 0;
    vector<int> h;
    vector<int> ans;
    void dfs(TreeNode* root) {
        n = max(n, root->val);
        while(h.size() < n) h.push_back(0);
        h[root->val-1] = 0;
        if(root->left) dfs(root->left), h[root->val-1] = max(h[root->val-1], h[root->left->val-1] + 1);
        if(root->right) dfs(root->right), h[root->val-1] = max(h[root->val-1], h[root->right->val-1] + 1);
    }
    void dfs2(TreeNode* root, int secondary) {
        int hl = root->left ? h[root->left->val - 1] : -1;
        int hr = root->right ? h[root->right->val - 1] : -1;
        if(hl == hr) return;
        if(hl > hr) {
            secondary = max(secondary, hr);
            ans[root->left->val-1] += secondary - hl;
            dfs2(root->left, secondary - 1);
        } else if(hl < hr) {
            secondary = max(secondary, hl);
            ans[root->right->val-1] += secondary - hr;
            dfs2(root->right, secondary - 1);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        dfs(root);
        ans.assign(n, h[root->val-1]);
        dfs2(root, -1);
        vector<int> ret;
        for(const auto &i: queries) {
            ret.push_back(ans[i-1]);
        }
        return ret;
    }
};