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
    bool solve(TreeNode* left, TreeNode *right) {
        if(!left && !right) return 1;
        if(!left || !right) return 0;
        if(left->val != right->val) return 0;
        if(!solve(left->right, right->left)) return 0;
        if(!solve(left->left, right->right)) return 0;
        return 1;
    }
    bool isSymmetric(TreeNode* root) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        if(!root) return 1;
        return solve(root->left, root->right);
    }
};