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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        while(head) {
            if(head->val == 0) v.push_back(0);
            else v.back() += head->val;
            head = head->next;
        }
        v.pop_back();
        ListNode *ret = NULL;
        while(!v.empty()) {
            ret = new ListNode(v.back(), ret);
            v.pop_back();
        }
        return ret;
    }
};