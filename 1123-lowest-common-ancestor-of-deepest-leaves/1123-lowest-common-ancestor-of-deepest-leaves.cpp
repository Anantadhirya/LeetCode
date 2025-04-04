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
    pair<TreeNode*, int> dfs(TreeNode* curr) {
        if(!curr) {
            return {curr, 0};
        }
        auto l = dfs(curr->left);
        auto r = dfs(curr->right);
        if(l.second == r.second) return {curr, l.second+1};
        else if(l.second > r.second) return {l.first, l.second+1};
        else return {r.first, r.second+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};