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
    array<int, 3> solve(TreeNode *cur) {
        if(!cur) return {0, 0, 0};
        auto l = solve(cur->left);
        auto r = solve(cur->right);
        int sm = cur->val + l[1] + r[1];
        int cnt = 1 + l[2] + r[2];
        return {l[0] + r[0] + (sm/cnt == cur->val), sm, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root)[0];
    }
};