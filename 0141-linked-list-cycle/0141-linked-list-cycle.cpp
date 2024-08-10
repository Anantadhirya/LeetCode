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
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const int inf = INT_MAX;
        while(head) {
            if(head->val == inf) return 1;
            head->val = inf;
            head = head->next;
        }
        return 0;
    }
};