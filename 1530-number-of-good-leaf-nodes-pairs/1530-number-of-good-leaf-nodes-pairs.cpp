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
    vector<int> dfs(TreeNode* curr, int &distance, int &ans) {
        if(!curr) return {};
        if(!curr->left && !curr->right) return {1};
        vector<int> l = dfs(curr->left, distance, ans);
        vector<int> r = dfs(curr->right, distance, ans);
        for(int i = l.size() - 1; i >= 0; i--) {
            for(int j = r.size() - 1; j >= 0; j--) {
                if(i+j+2 <= distance) {
                    ans += l[i] * r[j];
                }
            }
        }
        vector<int> ret(distance, 0);
        for(int i = 1; i < distance; i++) {
            ret[i] += (i-1 < l.size() ? l[i-1] : 0) + (i-1 < r.size() ? r[i-1] : 0);
        }
        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};