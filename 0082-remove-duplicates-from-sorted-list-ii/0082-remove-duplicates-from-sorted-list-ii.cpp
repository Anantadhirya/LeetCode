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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> cnt;
        for(ListNode *i = head; i; i = i->next) {
            cnt[i->val]++;
        }
        head = new ListNode(-1, head);
        for(ListNode *i = head; i; i = i->next) {
            while(i->next && cnt[i->next->val] > 1) {
                i->next = i->next->next;
            }
        }
        return head->next;
    }
};