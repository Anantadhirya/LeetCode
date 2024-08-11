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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        vector<ListNode*> v;
        while(head) {
            v.push_back(head);
            head = head->next;
        }
        int n = v.size();
        k %= n;
        v.back()->next = v[0];
        v[(n-k-1+n)%n]->next = NULL;
        head = v[(n-k) % n];
        return head;
    }
};