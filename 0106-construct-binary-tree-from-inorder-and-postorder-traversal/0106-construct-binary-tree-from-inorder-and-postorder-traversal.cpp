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
    TreeNode* solve(int l, int r, int l2, int r2, vector<int> &inorder, vector<int> &postorder, map<int, int> &pos) {
        if(r < l) return NULL;
        TreeNode* ret = new TreeNode(postorder[r]);
        int idx = pos[postorder[r]];
        int mid = l + (idx-l2);
        ret->left = solve(l, mid-1, l2, idx-1, inorder, postorder, pos);
        ret->right = solve(mid, r-1, idx+1, r2, inorder, postorder, pos);
        return ret;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> pos;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        return solve(0, n-1, 0, n-1, inorder, postorder, pos);
    }
};