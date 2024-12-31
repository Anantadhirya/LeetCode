class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1, d1 = n-1, d7 = n-1, d30 = n-1; i >= 0; i--) {
            while(days[d1] >= days[i] + 1) d1--;
            while(days[d7] >= days[i] + 7) d7--;
            while(days[d30] >= days[i] + 30) d30--;
            dp[i] = min(dp[d1+1] + costs[0], min(dp[d7+1] + costs[1], dp[d30+1] + costs[2]));
        }
        return dp[0];
    }
};