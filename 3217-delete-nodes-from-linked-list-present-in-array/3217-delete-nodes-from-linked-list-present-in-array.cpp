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
    ListNode* solve(ListNode* head, set<int> &s) {
        if(!head) return head;
        if(s.count(head->val)) {
            return solve(head->next, s);
        }
        head->next = solve(head->next, s);
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        set<int> s(nums.begin(), nums.end());
        return solve(head, s);
    }
};