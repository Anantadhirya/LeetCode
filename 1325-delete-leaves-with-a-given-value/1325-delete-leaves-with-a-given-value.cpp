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
    void solve(TreeNode *root, int &target) {
        if(root->left) {
            solve(root->left, target);
            if(root->left->val == -1) {
                root->left = NULL;
            }
        }
        if(root->right) {
            solve(root->right, target);
            if(root->right->val == -1) {
                root->right = NULL;
            }
        }
        if(!root->left && !root->right && root->val == target) {
            root->val = -1;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        solve(root, target);
        return root->val == -1 ? NULL : root;
    }
};