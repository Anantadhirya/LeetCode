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

const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        TreeNode* curr;
        stack<TreeNode*> s;
        for(int i = 0, level, val; i < n; ) {
            level = val = 0;
            while(traversal[i] == '-') level++, i++;
            while(i < n && traversal[i] != '-') val = 10*val + (traversal[i]-'0'), i++;

            while(s.size() > level) s.pop();
            curr = new TreeNode(val);
            if(!s.empty()) {
                if(!s.top()->left) s.top()->left = curr;
                else s.top()->right = curr;
            }
            s.push(curr);
        }
        while(s.size() > 1) s.pop();
        return s.top();
    }
};