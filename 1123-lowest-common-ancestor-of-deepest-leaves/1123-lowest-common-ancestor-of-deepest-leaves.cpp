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
    void dfs(TreeNode* curr, unordered_map<int, int> &d) {
        d[curr->val] = 0;
        if(curr->left) {
            dfs(curr->left, d);
            d[curr->val] = max(d[curr->val], d[curr->left->val] + 1);
        }
        if(curr->right) {
            dfs(curr->right, d);
            d[curr->val] = max(d[curr->val], d[curr->right->val] + 1);
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int, int> d;
        dfs(root, d);
        int dl, dr;
        while(root->left || root->right) {
            if(!root->left) root = root->right;
            else if(!root->right) root = root->left;
            else {
                dl = d[root->left->val];
                dr = d[root->right->val];
                if(dl == dr) break;
                else if(dl > dr) root = root->left;
                else root = root->right;
            }
        }
        return root;
    }
};