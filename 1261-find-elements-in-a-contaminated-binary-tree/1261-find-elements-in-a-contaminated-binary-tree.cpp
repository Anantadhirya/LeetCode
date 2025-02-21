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
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        for(TreeNode* curr; !q.empty(); q.pop()) {
            curr = q.front();
            s.insert(curr->val);
            if(curr->left) {
                curr->left->val = 2*curr->val + 1;
                q.push(curr->left);
            }
            if(curr->right) {
                curr->right->val = 2*curr->val + 2;
                q.push(curr->right);
            }
        }
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */