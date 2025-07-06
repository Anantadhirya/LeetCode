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
    void dfs(TreeNode *curr, vector<int> &path, vector<string> &ans) {
        path.push_back(curr->val);
        if(!curr->left && !curr->right) {
            ans.push_back(to_string(path[0]));
            for(int i = 1; i < path.size(); i++) {
                ans.back() += "->" + to_string(path[i]);
            }
        }
        if(curr->left) dfs(curr->left, path, ans);
        if(curr->right) dfs(curr->right, path, ans);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ans;
        dfs(root, path, ans);
        return ans;
    }
};