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
    void dfs(TreeNode* root, vector<vector<int>> &v, int level) {
        if(!root) return;
        if(level >= v.size()) v.push_back({});
        v[level].push_back(root->val);
        dfs(root->left, v, level+1);
        dfs(root->right, v, level+1);
    }
    int minimumOperations(TreeNode* root) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n;
        vector<vector<int>> v;
        dfs(root, v, 0);
        vector<int> v2;
        unordered_map<int, int> pos;
        int ans = 0;
        for(auto &i: v) {
            n = i.size();
            for(int j = 0; j < n; j++) {
                pos[i[j]] = j;
            }
            v2 = i;
            sort(v2.begin(), v2.end());
            for(int j = 0, k; j < n; j++) {
                if(i[j] != v2[j]) {
                    k = pos[v2[j]];
                    swap(i[j], i[k]);
                    swap(pos[i[j]], pos[i[k]]);
                    ans++;
                }
            }
        }
        return ans;
    }
};