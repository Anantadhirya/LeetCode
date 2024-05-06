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
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> ans;
        while(head) {
            while(!ans.empty() && ans.back() < head->val) ans.pop_back();
            ans.push_back(head->val);
            head = head->next;
        }
        ListNode *ret = NULL;
        for(int i = ans.size()-1; i >= 0; i--) {
            ret = new ListNode(ans[i], ret);
        }
        return ret;
    }
};