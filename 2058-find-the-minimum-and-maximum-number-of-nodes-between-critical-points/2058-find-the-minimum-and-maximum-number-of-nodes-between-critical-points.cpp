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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size(), fi = -1, lst = -1, ans1 = INT_MAX;
        for(int i = 1; i < n-1; i++) {
            if(v[i-1] > v[i] && v[i] < v[i+1] || v[i-1] < v[i] && v[i] > v[i+1]) {
                if(fi == -1) fi = i;
                if(lst != -1) {
                    ans1 = min(ans1, i-lst);
                }
                lst = i;
            }
        }
        if(fi == lst) return {-1, -1};
        return {ans1, lst - fi};
    }
};