/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, TreeNode* root, bool started) {
        if(!head) return 1;
        if(!root) return 0;
        if(root->val == head->val) {
            if(solve(head->next, root->left, 1) || solve(head->next, root->right, 1)) return 1;
        }
        if(!started) {
            if(solve(head, root->left, 0) || solve(head, root->right, 0)) return 1;
        }
        return 0;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head, root, 0);
    }
};