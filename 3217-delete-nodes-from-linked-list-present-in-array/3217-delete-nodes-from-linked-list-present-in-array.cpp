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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());
        vector<int> v;
        while(head) {
            if(!s.count(head->val)) {
                v.push_back(head->val);
            }
            head = head->next;
        }
        head = NULL;
        while(!v.empty()) {
            head = new ListNode(v.back(), head);
            v.pop_back();
        }
        return head;
    }
};