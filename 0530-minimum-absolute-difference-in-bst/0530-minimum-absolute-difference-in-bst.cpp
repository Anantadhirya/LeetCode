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
    void inorder(TreeNode* root, vector<int> &v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int ans = v[1] - v[0];
        int n = v.size();
        for(int i = 0; i+1 < n; i++) {
            ans = min(ans, v[i+1] - v[i]);
        }
        return ans;
    }
};