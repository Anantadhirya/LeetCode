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
    ListNode* partition(ListNode* head, int x) {
        vector<int> l, r;
        while(head) {
            if(head->val < x) l.push_back(head->val);
            else r.push_back(head->val);
            head = head->next;
        }
        while(!r.empty()) {
            head = new ListNode(r.back(), head);
            r.pop_back();
        }
        while(!l.empty()) {
            head = new ListNode(l.back(), head);
            l.pop_back();
        }
        return head;
    }
};