/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        while(1) {
            node->val = node->next->val;
            if(node->next->next) node = node->next;
            else {
                node->next = NULL;
                break;
            }
        }
    }
};