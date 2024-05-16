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
    bool solve(TreeNode* root) {
        int l = root->left ? solve(root->left) : (root->val == 3);
        int r = root->right ? solve(root->right) : (root->val == 3);
        if(root->val == 2) return l || r;
        if(root->val == 3) return l && r;
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        return solve(root);
    }
};