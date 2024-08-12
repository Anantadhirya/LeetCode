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
    int maxPathSum(TreeNode* root) {
        if(!root) return -1e9;
        int ansl = maxPathSum(root->left);
        int ansr = maxPathSum(root->right);
        int l = root->left ? root->left->val : 0;
        int r = root->right ? root->right->val : 0;
        int ans = max(max(ansl, ansr), root->val + l + r);
        root->val = max(0, root->val + max(0, max(l, r)));
        return ans;
    }
};