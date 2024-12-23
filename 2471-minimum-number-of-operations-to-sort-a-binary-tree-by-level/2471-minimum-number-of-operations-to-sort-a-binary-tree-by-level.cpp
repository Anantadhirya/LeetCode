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
    int minimumOperations(TreeNode* root) {
        int n, ans = 0;
        queue<TreeNode*> q;
        vector<pair<int, int>> v;

        q.push(root);
        while(!q.empty()) {
            n = q.size();
            v.resize(n);
            for(int i = 0; i < n; i++) {
                root = q.front();
                q.pop();

                v[i] = {root->val, i};
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            sort(v.begin(), v.end());
            for(int i = 0; i < n; i++) {
                while(v[i].second != i) {
                    swap(v[i], v[v[i].second]);
                    ans++;
                }
            }
        }
        return ans;
    }
};