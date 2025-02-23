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
    void solve(TreeNode *curr, int pre, int post, int sz, vector<int> &preorder, vector<int> &postorder, vector<int> &pos) {
        if(sz-1 == 0) return;
        int left_val = preorder[pre+1];
        int left_sz = pos[left_val] - post + 1;
        curr->left = new TreeNode(left_val);
        solve(curr->left, pre+1, post, left_sz, preorder, postorder, pos);

        if(sz-1-left_sz == 0) return;
        int right_val = preorder[pre+1+left_sz];
        int right_sz = sz-1-left_sz;
        curr->right = new TreeNode(right_val);
        solve(curr->right, pre+1+left_sz, post+left_sz, right_sz, preorder, postorder, pos);
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> pos(n+1);
        for(int i = 0; i < n; i++) {
            pos[postorder[i]] = i;
        }
        solve(root, 0, 0, n, preorder, postorder, pos);
        return root;
    }
};