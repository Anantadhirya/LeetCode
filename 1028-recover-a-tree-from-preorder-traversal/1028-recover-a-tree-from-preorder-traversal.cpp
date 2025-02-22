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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> split(1, {0, 0});
        int n = traversal.size();
        stack<pair<TreeNode*, int>> s;
        for(int i = 0; i < n; i++) {
            if(i > 0 && '0' <= traversal[i-1] && traversal[i-1] <= '9' && traversal[i] == '-') 
                split.push_back({0, 0});
            if(traversal[i] == '-') split.back().first++;
            else split.back().second = 10*split.back().second + (traversal[i] - '0');
        }
        TreeNode *root = new TreeNode(split[0].second);
        TreeNode *curr;
        int m = split.size();
        s.push({root, 0});
        for(int i = 1; i < m; i++) {
            curr = new TreeNode(split[i].second);
            while(s.top().second >= split[i].first) s.pop();
            if(!s.top().first->left) s.top().first->left = curr;
            else s.top().first->right = curr;
            s.push({curr, split[i].first});
        }
        return root;
    }
};