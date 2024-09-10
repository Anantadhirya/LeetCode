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
    void solve(ListNode *head) {
        if(!head || !head->next) return;
        ListNode *gcd = new ListNode(__gcd(head->val, head->next->val), head->next);
        head->next = gcd;
        solve(head->next->next);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        solve(head);
        return head;
    }
};