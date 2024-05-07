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
class Solution {
public:
    void f(ListNode *curr, int &sisa) {
        if(!curr) return;
        f(curr->next, sisa);
        curr->val = 2*curr->val + sisa;
        sisa = curr->val / 10;
        curr->val %= 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int sisa = 0;
        f(head, sisa);
        while(sisa > 0) {
            head = new ListNode(sisa%10, head);
            sisa /= 10;
        }
        return head;
    }
};