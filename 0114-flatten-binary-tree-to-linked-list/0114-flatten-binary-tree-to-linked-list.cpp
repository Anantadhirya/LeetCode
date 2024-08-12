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
    void flatten(TreeNode* root, TreeNode* end = NULL) {
        if(!root) return;
        if(!root->right) root->right = end;
        else flatten(root->right, end);
        if(root->left) {
            flatten(root->left, root->right);
            root->right = root->left;
        }
        root->left = NULL;
    }
};