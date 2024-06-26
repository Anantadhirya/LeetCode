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
    void dfs(TreeNode *curr, vector<int> &v) {
        if(!curr) return;
        dfs(curr->left, v);
        v.push_back(curr->val);
        dfs(curr->right, v);
    }
    void build(TreeNode *curr, int l, int r, vector<int> &v) {
        int mid = (l+r)/2;
        curr->val = v[mid];
        if(l <= mid-1) {
            curr->left = new TreeNode();
            build(curr->left, l, mid-1, v);
        }
        if(mid+1 <= r) {
            curr->right = new TreeNode();
            build(curr->right, mid+1, r, v);
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        TreeNode *ret = new TreeNode();
        build(ret, 0, v.size()-1, v);
        return ret;
    }
};