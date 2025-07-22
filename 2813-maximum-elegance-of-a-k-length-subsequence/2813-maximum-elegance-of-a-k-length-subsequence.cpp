class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<bool> b(n+1, 0);
        priority_queue<int> pq;
        long long tmp = 0, ans = 0, cnt = 0;
        for(int i = n-1; i >= n-k; i--) {
            tmp += items[i][0];
            if(b[items[i][1]]) pq.push(-items[i][0]);
            else b[items[i][1]] = 1, cnt++;
        }
        ans = tmp + cnt*cnt;
        for(int i = n-k-1; i >= 0 && !pq.empty(); i--) {
            if(b[items[i][1]]) continue;
            tmp += pq.top() + items[i][0];
            pq.pop();
            b[items[i][1]] = 1;
            cnt++;
            ans = max(ans, tmp + cnt*cnt);
        }
        return ans;
    }
};