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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        for(int i = 0; i+k-1 < n; i += k) {
            for(int l = i, r = i+k-1; l < r; l++, r--) {
                swap(v[l], v[r]);
            }
        }
        head = NULL;
        while(!v.empty()) {
            head = new ListNode(v.back(), head);
            v.pop_back();
        }
        return head;
    }
};