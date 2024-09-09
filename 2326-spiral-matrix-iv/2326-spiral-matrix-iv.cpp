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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int d = 0, ii, jj;
        while(head) {
            ans[i][j] = head->val;
            head = head->next;
            ii = i + dx[d];
            jj = j + dy[d];
            if(!(0 <= ii && ii < m && 0 <= jj && jj < n) || ans[ii][jj] != -1) {
                d = (d+1)%4;
            }
            i += dx[d];
            j += dy[d];
        }
        return ans;
    }
};