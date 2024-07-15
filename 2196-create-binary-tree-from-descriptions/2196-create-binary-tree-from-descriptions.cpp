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
    void build(TreeNode* curr, unordered_map<int, int> &l, unordered_map<int,int> &r) {
        if(l.count(curr->val)) {
            curr->left = new TreeNode(l[curr->val]);
            build(curr->left, l, r);
        }
        if(r.count(curr->val)) {
            curr->right = new TreeNode(r[curr->val]);
            build(curr->right, l, r);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_map<int, int> l, r;
        bitset<100005> child;
        TreeNode* root;
        for(const auto &i: descriptions) {
            if(i[2]) l[i[0]] = i[1];
            else r[i[0]] = i[1];
            child[i[1]] = 1;
        }
        for(const auto &i: descriptions) {
            if(!child[i[0]]) {
                root = new TreeNode(i[0]);
                break;
            }
        }
        build(root, l, r);
        return root;
    }
};