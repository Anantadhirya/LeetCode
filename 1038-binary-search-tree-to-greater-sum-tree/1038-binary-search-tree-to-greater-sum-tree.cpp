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
    int solve(TreeNode *curr, int smt = 0) {
        if(!curr) return 0;
        int smr = solve(curr->right, smt);
        curr->val += smr + smt;
        int sml = solve(curr->left, curr->val);
        return sml + curr->val - smt;
    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};