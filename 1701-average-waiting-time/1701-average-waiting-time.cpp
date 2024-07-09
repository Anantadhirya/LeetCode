class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = customers.size(), t = 0;
        double ans = 0;
        for(int i = 0; i < n; i++) {
            t = max(t, customers[i][0]) + customers[i][1];
            ans += t - customers[i][0];
        }
        return ans / n;
    }
};