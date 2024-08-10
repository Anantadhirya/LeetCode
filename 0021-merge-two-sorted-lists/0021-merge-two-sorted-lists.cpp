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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        bool p2;
        while(list1 || list2) {
            if(!list1) p2 = 1;
            else if(!list2) p2 = 0;
            else p2 = (list2->val < list1->val);

            if(p2) {
                v.push_back(list2->val);
                list2 = list2->next;
            } else {
                v.push_back(list1->val);
                list1 = list1->next;
            }
        }
        ListNode *ans = NULL;
        while(!v.empty()) {
            ans = new ListNode(v.back(), ans);
            v.pop_back();
        }
        return ans;
    }
};