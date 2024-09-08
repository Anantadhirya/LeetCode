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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<ListNode*> v;
        for(ListNode *curr = head; curr; curr = curr->next) {
            v.push_back(curr);
        }
        int n = v.size();
        vector<ListNode*> ans(k);
        for(int i = 0, j = 0; i < k; i++) {
            if(j != 0) v[j-1]->next = NULL;
            ans[i] = (j < n ? v[j] : NULL);
            j += (n/k) + (i < n%k);
        }
        return ans;
    }
};