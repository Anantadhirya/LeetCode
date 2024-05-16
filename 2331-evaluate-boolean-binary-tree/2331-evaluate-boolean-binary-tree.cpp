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
    bool evaluateTree(TreeNode* root) {
        int l = root->left ? evaluateTree(root->left) : (root->val == 3);
        int r = root->right ? evaluateTree(root->right) : (root->val == 3);
        if(root->val == 2) return l || r;
        if(root->val == 3) return l && r;
        return root->val;
    }
};