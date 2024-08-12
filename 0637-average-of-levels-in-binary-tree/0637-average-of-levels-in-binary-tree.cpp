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
    void dfs(TreeNode* root, int d, vector<double> &ans, vector<int> &cnt) {
        if(!root) return;
        if(d >= ans.size()) {
            ans.push_back(0);
            cnt.push_back(0);
        }
        ans[d] += root->val;
        cnt[d]++;
        dfs(root->left, d+1, ans, cnt);
        dfs(root->right, d+1, ans, cnt);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<int> cnt;
        dfs(root, 0, ans, cnt);
        for(int i = ans.size()-1; i >= 0; i--) {
            ans[i] /= cnt[i];
        }
        return ans;
    }
};