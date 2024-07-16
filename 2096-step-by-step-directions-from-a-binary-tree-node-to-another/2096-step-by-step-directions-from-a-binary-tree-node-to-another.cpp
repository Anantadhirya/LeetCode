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
    void getPath(TreeNode *root, int &target, string &ans, string &tmp) {
        if(!root) return;
        if(root->val == target) {
            ans = tmp;
            return;
        }
        tmp.push_back('L');
        getPath(root->left, target, ans, tmp);
        tmp.back() = 'R';
        getPath(root->right, target, ans, tmp);
        tmp.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        string pathStart = "", pathDest = "", tmp = "";
        getPath(root, startValue, pathStart, tmp);
        getPath(root, destValue, pathDest, tmp);
        int n = min(pathStart.size(), pathDest.size());
        int sama = -1;
        for(int i = 0; i < n; i++) {
            if(pathStart[i] == pathDest[i]) sama = i;
            else break;
        }
        pathStart = sama+1 < pathStart.size() ? pathStart.substr(sama+1) : "";
        pathDest = sama+1 < pathDest.size() ? pathDest.substr(sama+1) : "";
        string ans(pathStart.size(), 'U');
        ans += pathDest;
        return ans;
    }
};