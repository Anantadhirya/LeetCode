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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> v;
        for(ListNode *i = head; i; i = i->next) {
            v.push_back(i);
        }
        left--, right--;

        for(int i = left+1; i <= right; i++) {
            v[i]->next = v[i-1];
        }

        if(left-1 >= 0) v[left-1]->next = v[right];
        else head = v[right];

        if(right+1 < v.size()) v[left]->next = v[right+1];
        else v[left]->next = NULL;

        return head;
    }
};