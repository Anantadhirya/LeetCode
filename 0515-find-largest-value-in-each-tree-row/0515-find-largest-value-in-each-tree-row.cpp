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
    void dfs(TreeNode *curr, vector<int> &ans, int level) {
        if(!curr) return;
        if(level == ans.size()) ans.push_back(curr->val);
        ans[level] = max(ans[level], curr->val);
        dfs(curr->left, ans, level+1);
        dfs(curr->right, ans, level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};